// Copyright 2018-19 Eric Fedosejevs

#pragma once

#include "Sirelphy/source/precomp.h"

// Built-in dimensions
template <
	class Amount = std::ratio<0>,
	class Length = std::ratio<0>,
	class Time = std::ratio<0>,
	class Energy = std::ratio<0>,
	class Charge = std::ratio<0>,
	class Angle = std::ratio<0>
>
struct unitDimensions {
	static constexpr long long amount_num = Amount::num;
	static constexpr long long amount_den = Amount::den;
	static constexpr long long length_num = Length::num;
	static constexpr long long length_den = Length::den;
	static constexpr long long time_num = Time::num;
	static constexpr long long time_den = Time::den;
	static constexpr long long energy_num = Energy::num;
	static constexpr long long energy_den = Energy::den;
	static constexpr long long charge_num = Charge::num;
	static constexpr long long charge_den = Charge::den;
	static constexpr long long angle_num = Angle::num;
	static constexpr long long angle_den = Angle::den;
};

template <class LHS, class RHS>
struct _unitDimensions_add { // add two ratios
	//static_assert(_Is_ratio_v<_R1>&& _Is_ratio_v<_R2>, "ratio_add<R1, R2> requires R1 and R2 to be ratio<>s.");

	// redirection necessary to make this possible
	using type = typename unitDimensions<
		std::ratio_add<std::ratio<LHS::amount_num, LHS::amount_den>, std::ratio<LHS::amount_num, LHS::amount_den>>,
		std::ratio_add<std::ratio<LHS::length_num, LHS::length_den>, std::ratio<LHS::length_num, LHS::length_den>>,
		std::ratio_add<std::ratio<LHS::time_num, LHS::time_den>, std::ratio<LHS::time_num, LHS::time_den>>,
		std::ratio_add<std::ratio<LHS::energy_num, LHS::energy_den>, std::ratio<LHS::energy_num, LHS::energy_den>>,
		std::ratio_add<std::ratio<LHS::charge_num, LHS::charge_den>, std::ratio<LHS::charge_num, LHS::charge_den>>,
		std::ratio_add<std::ratio<LHS::angle_num, LHS::angle_den>, std::ratio<LHS::angle_num, LHS::angle_den>>
	>;
};

template <class LHS, class RHS>
using unitDimensions_add = typename _unitDimensions_add<LHS, RHS>::type;

template <class LHS, class RHS>
struct _unitDimensions_subtract { // add two ratios
	//static_assert(_Is_ratio_v<_R1>&& _Is_ratio_v<_R2>, "ratio_add<R1, R2> requires R1 and R2 to be ratio<>s.");

	// redirection necessary to make this possible
	using type = typename unitDimensions<
		std::ratio_subtract<std::ratio<LHS::amount_num, LHS::amount_den>, std::ratio<LHS::amount_num, LHS::amount_den>>,
		std::ratio_subtract<std::ratio<LHS::length_num, LHS::length_den>, std::ratio<LHS::length_num, LHS::length_den>>,
		std::ratio_subtract<std::ratio<LHS::time_num, LHS::time_den>, std::ratio<LHS::time_num, LHS::time_den>>,
		std::ratio_subtract<std::ratio<LHS::energy_num, LHS::energy_den>, std::ratio<LHS::energy_num, LHS::energy_den>>,
		std::ratio_subtract<std::ratio<LHS::charge_num, LHS::charge_den>, std::ratio<LHS::charge_num, LHS::charge_den>>,
		std::ratio_subtract<std::ratio<LHS::angle_num, LHS::angle_den>, std::ratio<LHS::angle_num, LHS::angle_den>>
	>;
};

template <class LHS, class RHS>
using unitDimensions_subtract = typename _unitDimensions_subtract<LHS, RHS>::type;
