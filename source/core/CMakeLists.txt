cmake_minimum_required(VERSION 3.10)

add_library(SirelphyCore STATIC
    interface/object_interface.cpp
    interface/object_interface.h
    interface/universe_interface.cpp
    interface/universe_interface.h
    physics/forces/forces.cpp
    physics/forces/forces.h
    physics/forces/gravity.cpp
    physics/forces/gravity.h
    physics/forces/property.cpp
    physics/forces/property.h
    physics/helpers/bounding.cpp
    physics/helpers/bounding.h
    physics/helpers/ntree.decl.h
    physics/helpers/ntree.h
    physics/helpers/octree.h
    physics/objects/blop.h
    physics/objects/frame.cpp
    physics/objects/frame.h
    physics/objects/object.cpp
    physics/objects/object.h
    physics/objects/object_compound.cpp
    physics/objects/object_compound.h
    physics/objects/origin.h
    physics/objects/particle.cpp
    physics/objects/particle.h
    physics/objects/particleclass.cpp
    physics/objects/particleclass.h
    physics/relativity.h
    physics/universe/scenemanager.h
    physics/universe/universe.cpp
    physics/universe/universe.h
    physics/vector/special/vector_length.h
    physics/vector/special/vector_lengthtime.h
    physics/vector/special/vector_unit3d.h
    physics/vector/special/vector_velocity.h
    physics/vector/vector.decl.h
    physics/vector/vector.h
    precomp.cpp
    "unitlib/helpers/constants_private.h"
    unitlib/helpers/dimension_fundamentals.h
    unitlib/helpers/dimension_templates.h
    unitlib/helpers/helper_macros.h
    unitlib/helpers/macro_debugging.h
    unitlib/helpers/si_prefixes.h
    unitlib/units.h
    unitlib/units/angle.h
    unitlib/units/base.h
    unitlib/units/energy.cpp
    unitlib/units/energy.h
    unitlib/units/length.h
    unitlib/units/mass.h
    unitlib/units/temperature.h
    unitlib/units/time.h
    unitlib/units/velocity.h
)

target_precompile_headers(SirelphyCore
	PRIVATE precomp.h)
	
target_config_compiler(SirelphyCore)

set_target_properties(SirelphyCore PROPERTIES
           CXX_STANDARD ${OVERRIDE_CXX_STANDARD}
           CXX_EXTENSIONS OFF
           )