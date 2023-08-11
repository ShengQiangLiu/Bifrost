/*******************************************************
 * @author      : dog head
 * @date        : Created in 2023/6/20 9:55 上午
 * @mail        : qw225967@github.com
 * @project     : worker
 * @file        : publisher.h
 * @description : TODO
 *******************************************************/

#ifndef WORKER_PUBLISHER_H
#define WORKER_PUBLISHER_H

#include <map>

#include "data_producer.h"
#include "experiment_manager.h"
#include "nack.h"
#include "quic_clock_adapter.h"
#include "quiche/quic/core/congestion_control/send_algorithm_interface.h"
#include "rtcp_quic_feedback.h"
#include "rtcp_rr.h"
#include "rtcp_sr.h"
#include "rtcp_tcc.h"
#include "setting.h"
#include "tcc_client.h"
#include "uv_loop.h"
#include "uv_timer.h"

namespace bifrost {
typedef std::shared_ptr<sockaddr> SockAddressPtr;
typedef std::shared_ptr<DataProducer> DataProducerPtr;
typedef std::shared_ptr<TransportCongestionControlClient>
    TransportCongestionControlClientPtr;
typedef std::shared_ptr<Nack> NackPtr;
class Publisher : public UvTimer::Listener,
                  public TransportCongestionControlClient::Observer {
 public:
  class Observer {
   public:
    virtual void OnPublisherSendPacket(RtpPacketPtr packet,
                                       const struct sockaddr* remote_addr) = 0;
    virtual void OnPublisherSendRtcpPacket(
        CompoundPacketPtr packet, const struct sockaddr* remote_addr) = 0;
  };

 public:
  void ReceiveFeedbackTransport(const FeedbackRtpTransportPacket* feedback) {
    if (this->congestion_type_ != quic::kGoogCC)
      return;

    if (this->tcc_client_ != nullptr) {
      this->tcc_client_->ReceiveRtcpTransportFeedback(feedback);
      this->pacer_bits_ = this->tcc_client_->get_available_bitrate();
    }
  }
  void ReceiveSendAlgorithmFeedback(QuicAckFeedbackPacket* feedback);
  void OnReceiveNack(FeedbackRtpNackPacket* packet);
  void OnReceiveReceiverReport(ReceiverReport* report);
  void OnSendPacketInNack(RtpPacketPtr& packet) {
    nack_->OnSendRtpPacket(packet);
  }

  SenderReport* GetRtcpSenderReport(uint64_t nowMs);

 public:
  Publisher(Settings::Configuration& remote_config, UvLoop** uv_loop,
            Observer* observer, uint8_t number,
            ExperimentManagerPtr& experiment_manager,
            quic::CongestionControlType quic_congestion_type);
  ~Publisher() {
    feedback_lost_no_count_packet_vec_.clear();
    pacer_vec_.clear();
    delete producer_timer_;
    delete data_dump_timer_;
    delete send_report_timer_;

    if (clock_ != nullptr) delete clock_;

    if (send_algorithm_interface_ != nullptr) delete send_algorithm_interface_;

    if (rtt_stats_ != nullptr) delete rtt_stats_;

    if (unacked_packet_map_ != nullptr) delete unacked_packet_map_;

    if (random_ != nullptr) delete random_;

    if (connection_stats_ != nullptr) delete connection_stats_;

    if (tcc_client_ != nullptr) tcc_client_.reset();

    data_producer_.reset();
  }
  // UvTimer
  void OnTimer(UvTimer* timer) override;

  // TransportCongestionControlClient::Observer
  void OnTransportCongestionControlClientBitrates(
      TransportCongestionControlClient* tcc_client,
      TransportCongestionControlClient::Bitrates& bitrates) override {}
  void OnTransportCongestionControlClientSendRtpPacket(
      TransportCongestionControlClient* tcc_client, RtpPacket* packet,
      const webrtc::PacedPacketInfo& pacing_info) override {}

 private:
  uint32_t TimerSendPacket(int32_t available);
  void RemoveOldSendPacket();
  void GetRtpExtensions(RtpPacketPtr &packet);

 private:
  /* ------------ base ------------ */
  // observer
  Observer* observer_;
  // remote addr
  SockAddressPtr udp_remote_address_;
  // addr config
  Settings::Configuration remote_addr_config_;
  // uv
  UvLoop* uv_loop_;
  UvTimer* producer_timer_;
  UvTimer* data_dump_timer_;
  UvTimer* send_report_timer_;
  // ssrc
  uint32_t ssrc_;
  // number
  uint8_t number_;
  // experiment manager
  ExperimentManagerPtr experiment_manager_;
  /* ------------ base ------------ */

  /* ------------ experiment ------------ */
  // pacer vec
  std::vector<RtpPacketPtr> pacer_vec_;
  // sr
  uint32_t send_packet_count_{0u};
  uint64_t send_packet_bytes_{0u};
  uint64_t max_packet_ms_{0u};
  uint64_t max_packet_ts_{0u};
  // send packet producer
  DataProducerPtr data_producer_;
  // send report
  float rtt_ = 0;
  // congestion_type
  quic::CongestionControlType congestion_type_;
  // tcc
  uint16_t tcc_seq_ = 0;
  TransportCongestionControlClientPtr tcc_client_{nullptr};
  // pacer bytes
  uint32_t pacer_bits_;
  int32_t pre_remind_bytes_ = 0;
  uint32_t send_bits_prior_ = 0;
  // nack
  NackPtr nack_;
  // quic send algorithm interface
  bool is_app_limit_{false};
  quic::SendAlgorithmInterface* send_algorithm_interface_{nullptr};
  quic::QuicClock* clock_{nullptr};
  quic::RttStats* rtt_stats_{nullptr};
  quic::QuicUnackedPacketMap* unacked_packet_map_{nullptr};
  quic::QuicRandom* random_{nullptr};
  quic::QuicConnectionStats* connection_stats_{nullptr};
  quic::AckedPacketVector acked_packets_;
  quic::LostPacketVector losted_packets_;
  quic::QuicByteCount bytes_in_flight_{0u};
  std::map<uint16_t, SendPacketInfo> has_send_map_;
  std::vector<SendPacketInfo> feedback_lost_no_count_packet_vec_;
  int64_t transport_rtt_{0u};
  uint16_t largest_acked_seq_{0u};
  int32_t cwnd_{6000u};
  /* ------------ experiment ------------ */
};
}  // namespace bifrost

#endif  // WORKER_PUBLISHER_H
