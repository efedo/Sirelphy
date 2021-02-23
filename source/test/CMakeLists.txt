cmake_minimum_required(VERSION 3.10)

include(${UTILOGENY_DIR}/cmake/target_add_googletest.cmake)
include(${UTILOGENY_DIR}/cmake/target_add_tbb.cmake)

add_executable(SirelphyTest
	pch.cpp
	pch.h
	test.cpp
)

target_precompile_headers(SirelphyTest
	PRIVATE pch.h)
	
target_config_compiler(SirelphyTest)

set_target_properties(SirelphyTest PROPERTIES
            CXX_STANDARD ${OVERRIDE_CXX_STANDARD}
            CXX_EXTENSIONS OFF
            )
			
target_link_tbb(SirelphyTest)			
target_link_gtest(SirelphyTest)
target_link_libraries(SirelphyTest SirelphyCore UtilogenyCore)

