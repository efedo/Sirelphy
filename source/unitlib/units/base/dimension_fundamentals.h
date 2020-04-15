// Copyright 2018-19 Eric Fedosejevs

#pragma once

#include "Sirelphy/source/precomp.h"
#include "Sirelphy/source/unitlib/units/base/dimension_templates.h"

// Fundamental Units
typedef unitDimensions<>																							dim_none;
typedef unitDimensions<std::ratio<1>>																				dim_amount;
typedef unitDimensions<std::ratio<0>, std::ratio<1>>																dim_length;
typedef unitDimensions<std::ratio<0>, std::ratio<0>, std::ratio<1>>													dim_time;
typedef unitDimensions<std::ratio<0>, std::ratio<0>, std::ratio<0>, std::ratio<1>>									dim_energy;
typedef unitDimensions<std::ratio<0>, std::ratio<0>, std::ratio<0>, std::ratio<0>, std::ratio<1>>					dim_charge;
typedef unitDimensions<std::ratio<0>, std::ratio<0>, std::ratio<0>, std::ratio<0>, std::ratio<0>, std::ratio<1>>	dim_angle;

// Derived Units
typedef unitDimensions<std::ratio<0>, std::ratio<2>>																dim_area;
typedef unitDimensions<std::ratio<0>, std::ratio<3>>																dim_volume;
typedef unitDimensions<std::ratio<0>, std::ratio<-3>, std::ratio<1>>												dim_density_mass;
typedef unitDimensions<std::ratio<1>, std::ratio<-3>>																dim_density_amount;
typedef unitDimensions<std::ratio<0>, std::ratio<0>, std::ratio<0>, std::ratio<1>>									dim_mass;

// energy = M L2 T?2
// energy = M c2
// c2 * T2 = L2

typedef unitDimensions<std::ratio<0>, std::ratio<0>, std::ratio<-1>, std::ratio<0>, std::ratio<1>>					dim_current; // current = charge / time
typedef unitDimensions<std::ratio<-1>, std::ratio<0>, std::ratio<0>, std::ratio<1>>									dim_temperature; // temperature = energy / amount
typedef unitDimensions<std::ratio<0>, std::ratio<0>, std::ratio<-1>>												dim_frequency; // frequency = 1 / time
typedef unitDimensions<std::ratio<0>, std::ratio<1>, std::ratio<-1>>												dim_velocity; // velocity = length / time
typedef unitDimensions<std::ratio<0>, std::ratio<0>, std::ratio<-1>, std::ratio<0>, std::ratio<0>, std::ratio<1>>	dim_angular_velocity; // angular velocity = angle / time
typedef unitDimensions<std::ratio<0>, std::ratio<1>, std::ratio<-2>>													dim_acceleration; // acceleration = length / time^2

typedef unitDimensions<std::ratio<0>, std::ratio<-1>, std::ratio<0>, std::ratio<1>>									dim_force; // force = energy / length;
//typedef unitDimensions<std::ratio<0>, std::ratio<1>, std::ratio<-2>, std::ratio<1>>								dim_force; // force = length * mass / time^2


typedef unitDimensions<std::ratio<0>, std::ratio<-1>, std::ratio<-2>, std::ratio<1>>								dim_pressure; // pressure = energy / length * time^2
typedef unitDimensions<std::ratio<0>, std::ratio<0>, std::ratio<-1>, std::ratio<1>>									dim_power; // power = energy / time
typedef unitDimensions<std::ratio<0>, std::ratio<0>, std::ratio<0>, std::ratio<1>, std::ratio<-1>>					dim_voltage; // voltage = energy / charge

typedef unitDimensions<std::ratio<2>, std::ratio<1>, std::ratio<-2>>												dim_torque;	///< Represents an SI derived unit of torque


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