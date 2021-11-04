cmake_minimum_required(VERSION 3.10)

add_library(SirelphyCore STATIC
    interface/object_interface.h
    physics/helpers/bounding.h
    physics/helpers/ntree.decl.h
    physics/helpers/ntree.h
    physics/helpers/octree.h
    physics/vector/vector.decl.h
    physics/vector/vector.h
    physics/forces/forces.h
    physics/forces/property.h
    physics/objects/blop.h
    physics/objects/frame.h
    physics/forces/gravity.h
    physics/objects/object.h
    physics/objects/object_compound.h
    physics/objects/origin.h
    physics/universe/scenemanager.h
    interface/universe_interface.h
    physics/vector/special/vector_unit3d.h
    physics/objects/particle.h
    physics/objects/particleclass.h
    physics/relativity.h
    physics/universe/universe.h
    physics/vector/special/vector_length.h
    physics/vector/special/vector_lengthtime.h
    physics/vector/special/vector_velocity.h
    sirelphy.h
    unitlib/constants.h
    unitlib/macro_debugging.h
    unitlib/si_prefixes.h
    unitlib/unitlib.h
    unitlib/units/base/dimension_fundamentals.h
    unitlib/units/base/dimension_templates.h
    unitlib/units/energy.h
    unitlib/units/angle.h
    unitlib/units/helper_macros.h
    unitlib/units/length.h
    unitlib/units/base/baseunit.h
    unitlib/units/mass.h
    unitlib/units/dimensionless.h
    unitlib/units/temperature.h
    unitlib/units/time.h
    unitlib/units/velocity.h
    interface/object_interface.cpp
    physics/helpers/bounding.cpp
    precomp.cpp
	precomp.h
    physics/forces/forces.cpp
    physics/forces/property.cpp
    physics/objects/frame.cpp
    physics/forces/gravity.cpp
    physics/objects/object.cpp
    physics/objects/object_compound.cpp
    interface/universe_interface.cpp
    physics/objects/particle.cpp
    physics/objects/particleclass.cpp
    physics/universe/universe.cpp
    sirelphy.cpp
    
    
    
 "unitlib/units/energy.cpp")

target_precompile_headers(SirelphyCore
	PRIVATE precomp.h)
	
target_config_compiler(SirelphyCore)

set_target_properties(SirelphyCore PROPERTIES
           CXX_STANDARD ${OVERRIDE_CXX_STANDARD}
           CXX_EXTENSIONS OFF
           )