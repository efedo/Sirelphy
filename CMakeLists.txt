# Copyright 2021 Eric Fedosejevs
#

cmake_minimum_required(VERSION 3.15)

# These are temporary and will be replaced with find_package eventually
set(UTILOGENY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../Utilogeny" CACHE STRING "Path to Utilogeny" FORCE)
set(SIRELPHY_DIR "${CMAKE_CURRENT_SOURCE_DIR}" CACHE STRING "Path to Sirelphy" FORCE)
include(${UTILOGENY_DIR}/cmake/setup_project.cmake)

pre_project_boilerplate(NAME "Sirelphy")

project(Sirelphy VERSION 1.0
                  DESCRIPTION "May eventually become a SImulated RELativistic PHYsics library. Under very early development."
                  LANGUAGES CXX)
				  
post_project_boilerplate(NAME "Sirelphy")

if(NOT TARGET UtilogenyCore)
	add_subdirectory(${UTILOGENY_DIR} ${CMAKE_BINARY_DIR}/lib/Utilogeny)
endif()

add_subdirectory(source/core)
add_subdirectory(source/test)

install(TARGETS SirelphyCore DESTINATION lib)
install(TARGETS SirelphyTest DESTINATION bin)