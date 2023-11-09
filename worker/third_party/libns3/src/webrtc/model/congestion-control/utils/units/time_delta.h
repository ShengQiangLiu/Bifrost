/*
 *  Copyright (c) 2018 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef API_UNITS_TIME_DELTA_H_
#define API_UNITS_TIME_DELTA_H_



#include <cstdlib>
#include <string>
#include <type_traits>
#include "unit_base.h"

 // TimeDelta represents the difference between two timestamps. Commonly this can
 // be a duration. However since two Timestamps are not guaranteed to have the
 // same epoch (they might come from different computers, making exact
 // synchronisation infeasible), the duration covered by a TimeDelta can be
 // undefined. To simplify usage, it can be constructed and converted to
 // different units, specifically seconds (s), milliseconds (ms) and
 // microseconds (us).
 namespace rtc {
class TimeDelta final : public RelativeUnit<TimeDelta> {
public:
	template <typename T>
	static constexpr TimeDelta Seconds(T value) {
		static_assert(std::is_arithmetic<T>::value, "");
		return FromFraction(1'000'000, value);
	}
	template <typename T>
	static constexpr TimeDelta Millis(T value) {
		static_assert(std::is_arithmetic<T>::value, "");
		return FromFraction(1'000, value);
	}
	template <typename T>
	static constexpr TimeDelta Micros(T value) {
		static_assert(std::is_arithmetic<T>::value, "");
		return FromValue(value);
	}

	TimeDelta() = delete;

	template <typename T = int64_t>
	constexpr T seconds() const {
		return ToFraction<1000000, T>();
	}
	template <typename T = int64_t>
	constexpr T ms() const {
		return ToFraction<1000, T>();
	}
	template <typename T = int64_t>
	constexpr T us() const {
		return ToValue<T>();
	}
	template <typename T = int64_t>
	constexpr T ns() const {
		return ToMultiple<1000, T>();
	}

	constexpr int64_t seconds_or(int64_t fallback_value) const {
		return ToFractionOr<1000000>(fallback_value);
	}
	constexpr int64_t ms_or(int64_t fallback_value) const {
		return ToFractionOr<1000>(fallback_value);
	}
	constexpr int64_t us_or(int64_t fallback_value) const {
		return ToValueOr(fallback_value);
	}

	constexpr TimeDelta Abs() const {
		return us() < 0 ? TimeDelta::Micros(-us()) : *this;
	}

private:
	friend class UnitBase<TimeDelta>;
	using RelativeUnit::RelativeUnit;
	static constexpr bool one_sided = false;
};
 } //namespace rtc

#endif  // API_UNITS_TIME_DELTA_H_