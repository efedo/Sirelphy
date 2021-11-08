// Copyright 2018-19 Eric Fedosejevs

#pragma once

#include "Sirelphy/source/core/precomp.h"
#include "Sirelphy/source/core/unitlib/helpers/dimension_templates.h"

namespace _units_private {

	// Some deviations from 2019 SI units, since I disagree with the fundamental units that were selected.
	// Deviations: using charge instead of current, excluding candela (since it has no business being a fundamental unit), 
	// including angle as a fundemental unit (has at least as much business being one as molar amount).
	// May also switch to derived temperature in the future;

	typedef unitDimensions<>																												dim_none;
	typedef unitDimensions<std::ratio< 1>>																									dim_time;        // T
	typedef unitDimensions<std::ratio< 0>, std::ratio< 1>>																					dim_length;      // L
	typedef unitDimensions<std::ratio< 0>, std::ratio< 0>, std::ratio< 1>>																	dim_mass;        // M
	typedef unitDimensions<std::ratio< 0>, std::ratio< 0>, std::ratio< 0>, std::ratio< 1>>													dim_charge;      // Q
	typedef unitDimensions<std::ratio< 0>, std::ratio< 0>, std::ratio< 0>, std::ratio< 0>, std::ratio< 1>>									dim_temperature; // K
	typedef unitDimensions<std::ratio< 0>, std::ratio< 0>, std::ratio< 0>, std::ratio< 0>, std::ratio< 0>, std::ratio< 1>>					dim_amount;      // N
	typedef unitDimensions<std::ratio< 0>, std::ratio< 0>, std::ratio< 0>, std::ratio< 0>, std::ratio< 0>, std::ratio< 0>, std::ratio< 1>>	dim_angle;		 // A

	// Derived Units
	typedef unitDimensions<std::ratio< 0>, std::ratio< 2>>																					dim_area;
	typedef unitDimensions<std::ratio< 0>, std::ratio< 3>>																					dim_volume;
	typedef unitDimensions<std::ratio<-1>, std::ratio< 1>>																					dim_velocity;
	typedef unitDimensions<std::ratio<-2>, std::ratio< 2>, std::ratio< 1>>																	dim_energy;
	typedef unitDimensions<std::ratio<-1>, std::ratio< 0>, std::ratio< 0>, std::ratio< 1>>													dim_current;      // Q

	// 28 depth * 29 width * 66 height
	
	//typedef unitDimensions<std::ratio<0>, std::ratio<-3>, std::ratio<1>>												dim_density_mass;
	//typedef unitDimensions<std::ratio<1>, std::ratio<-3>>																dim_density_amount;

	//typedef unitDimensions<std::ratio<0>, std::ratio<0>, std::ratio<-1>, std::ratio<0>, std::ratio<1>>					dim_current; // current = charge / time
	//typedef unitDimensions<std::ratio<-1>, std::ratio<0>, std::ratio<0>, std::ratio<1>>									; // temperature = energy / amount
	//typedef unitDimensions<std::ratio<0>, std::ratio<0>, std::ratio<-1>>												dim_frequency; // frequency = 1 / time
	//typedef unitDimensions<std::ratio<0>, std::ratio<0>, std::ratio<-1>, std::ratio<0>, std::ratio<0>, std::ratio<1>>	dim_angular_velocity; // angular velocity = angle / time
	//typedef unitDimensions<std::ratio<0>, std::ratio<1>, std::ratio<-2>>												dim_acceleration; // acceleration = length / time^2

	//typedef unitDimensions<std::ratio<0>, std::ratio<-1>, std::ratio<0>, std::ratio<1>>									dim_force; // force = energy / length;
	//typedef unitDimensions<std::ratio<0>, std::ratio<1>, std::ratio<-2>, std::ratio<1>>								dim_force; // force = length * mass / time^2


	//typedef unitDimensions<std::ratio<0>, std::ratio<-1>, std::ratio<-2>, std::ratio<1>>								dim_pressure; // pressure = energy / length * time^2
	//typedef unitDimensions<std::ratio<0>, std::ratio<0>, std::ratio<-1>, std::ratio<1>>									dim_power; // power = energy / time
	//typedef unitDimensions<std::ratio<0>, std::ratio<0>, std::ratio<0>, std::ratio<1>, std::ratio<-1>>					dim_voltage; // voltage = energy / charge

	//typedef unitDimensions<std::ratio<2>, std::ratio<1>, std::ratio<-2>>												dim_torque;	///< Represents an SI derived unit of torque
		//dim_capacitance; // capacitance = charge / voltage = energy
	//dim_impedance;
	//dim_conductance;
	//dim_magnetic_flux;
	//dim_magnetic_field_strength
	//dim_inductance
	//dim_solid_angle;
	//dim_luminous_flux;
	//dim_illuminance;
	//dim_radioactivity;
}

