cmake_minimum_required(VERSION 3.10)

enable_testing()
cmake_policy(SET CMP0077 NEW)
SET(gtest_force_shared_crt ON "Use shared (DLL) run-time lib even when Google Test is built as static lib.")
add_subdirectory(${UTILOGENY_DIR}/lib/googletest-master ${CMAKE_BINARY_DIR}/lib/googletest-master/out)
include_directories(${UTILOGENY_DIR}/lib/googletest-master/googletest/include)

add_executable(SirelphyTest
	pch.cpp
	pch.h
	test.cpp
)

set_target_properties(SirelphyTest PROPERTIES
            CXX_STANDARD ${OVERRIDE_CXX_STANDARD}
            CXX_EXTENSIONS OFF
            )	

if (TARGET gtest)
	message(STATUS "Linking to Google test.")
	target_link_libraries(SirelphyTest gtest gtest_main)
else()
	message(FATAL_ERROR "Do not have Google test.")
endif()

target_link_libraries(SirelphyTest Sirelphy UtilogenyCore)

