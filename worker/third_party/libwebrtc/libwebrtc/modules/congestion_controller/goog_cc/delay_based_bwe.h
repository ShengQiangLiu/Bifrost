/*
 *  Copyright (c) 2016 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef MODULES_CONGESTION_CONTROLLER_GOOG_CC_DELAY_BASED_BWE_H_
#define MODULES_CONGESTION_CONTROLLER_GOOG_CC_DELAY_BASED_BWE_H_

#include <absl/types/optional.h>
#include <stddef.h>
#include <stdint.h>

#include <memory>
#include <vector>

#include "api/network_state_predictor.h"
#include "api/transport/network_types.h"
#include "api/transport/webrtc_key_value_config.h"
#include "modules/congestion_controller/goog_cc/delay_increase_detector_interface.h"
#include "modules/congestion_controller/goog_cc/probe_bitrate_estimator.h"
#include "modules/remote_bitrate_estimator/aimd_rate_control.h"
#include "modules/remote_bitrate_estimator/include/bwe_defines.h"
#include "modules/remote_bitrate_estimator/inter_arrival.h"
#include "rtc_base/constructor_magic.h"

namespace webrtc {
class RtcEventLog;

class DelayBasedBwe {
 public:
  struct Result {
    Result();
    Result(bool probe, DataRate target_bitrate);
    ~Result();
    bool updated;
    bool probe;
    DataRate target_bitrate = DataRate::Zero();
    bool recovered_from_overuse;
    bool backoff_in_alr;
  };

  explicit DelayBasedBwe(const WebRtcKeyValueConfig* key_value_config,
                         NetworkStatePredictor* network_state_predictor);
  virtual ~DelayBasedBwe();

  Result IncomingPacketFeedbackVector(
      const TransportPacketsFeedback& msg,
      absl::optional<DataRate> acked_bitrate,
      absl::optional<DataRate> probe_bitrate,
      absl::optional<NetworkStateEstimate> network_estimate, bool in_alr);
  void OnRttUpdate(TimeDelta avg_rtt);
  bool LatestEstimate(std::vector<uint32_t>* ssrcs, DataRate* bitrate) const;
  void SetStartBitrate(DataRate start_bitrate);
  void SetMinBitrate(DataRate min_bitrate);
  TimeDelta GetExpectedBwePeriod() const;
  void SetAlrLimitedBackoffExperiment(bool enabled);

  DataRate TriggerOveruse(Timestamp at_time,
                          absl::optional<DataRate> link_capacity);

  void ChangeWindowSize(size_t size) {
    if (delay_detector_.get()) {
      delay_detector_->ChangeWindowSize(size);
    }
  }

  std::vector<double> GetPrevTrend() { return delay_detector_->GetPrevTrend(); }

  void ChangeDynamicMinThreshold(double threshold) {
    if (delay_detector_.get()) {
      delay_detector_->ChangeDynamicMinThreshold(threshold);
    }
  }

  void SetNoBitrateIncreaseInAlr(bool flag) {
    rate_control_.SetNoBitrateIncreaseInAlr(flag);
  }

 private:
  friend class GoogCcStatePrinter;
  void IncomingPacketFeedback(const PacketResult& packet_feedback,
                              Timestamp at_time);
  Result MaybeUpdateEstimate(
      absl::optional<DataRate> acked_bitrate,
      absl::optional<DataRate> probe_bitrate,
      absl::optional<NetworkStateEstimate> state_estimate,
      bool recovered_from_overuse, bool in_alr, Timestamp at_time);
  // Updates the current remote rate estimate and returns true if a valid
  // estimate exists.
  bool UpdateEstimate(Timestamp now, absl::optional<DataRate> acked_bitrate,
                      DataRate* target_bitrate);

  const WebRtcKeyValueConfig* const key_value_config_;
  NetworkStatePredictor* network_state_predictor_;
  std::unique_ptr<InterArrival> inter_arrival_;
  std::unique_ptr<DelayIncreaseDetectorInterface> delay_detector_;
  Timestamp last_seen_packet_;
  bool uma_recorded_;
  AimdRateControl rate_control_;
  DataRate prev_bitrate_;
  BandwidthUsage prev_state_;
  bool alr_limited_backoff_enabled_;

  RTC_DISALLOW_IMPLICIT_CONSTRUCTORS(DelayBasedBwe);
};

}  // namespace webrtc

#endif  // MODULES_CONGESTION_CONTROLLER_GOOG_CC_DELAY_BASED_BWE_H_
