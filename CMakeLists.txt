cmake_minimum_required(VERSION 3.13)
project(cool_B)

add_library(${PROJECT_NAME})

if (WIN32)
set(pfx $<IF:$<STREQUAL:${CMAKE_GENERATOR_PLATFORM},win32>,x86,x64>)
else()
set(pfx "")
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib/${pfx}/$<CONFIG>
)
include_directories(include)

add_subdirectory(src)
