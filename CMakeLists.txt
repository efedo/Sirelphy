cmake_minimum_required(VERSION 3.10)

#set(CMAKE_VERBOSE_MAKEFILE ON)

project(Sirelphy VERSION 1.0
                  DESCRIPTION "Very nice project"
                  LANGUAGES CXX)

set(OVERRIDE_CXX_STANDARD 17)
				  
set(SIRELPHY_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(UTILOGENY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../Utilogeny)

message(STATUS "Utilogeny directory: ${UTILOGENY_DIR}")
message(STATUS "Sirelphy directory: ${UTILOGENY_DIR}")

include_directories("..")
include_directories("../lib/boost_1_75_0")

add_subdirectory(${UTILOGENY_DIR}/source/core ${CMAKE_BINARY_DIR}/lib/Utilogeny/core/out)
add_subdirectory(source/core)
add_subdirectory(source/test)

install(TARGETS Sirelphy DESTINATION lib)
install(TARGETS SirelphyTest DESTINATION bin)