cmake_minimum_required(VERSION 3.16.0)
project(QuanLySinhVien)
file(GLOB SOURCE ${CMAKE_SOURCE_DIR}/../source/*.cpp)
include_directories(${CMAKE_SOURCE_DIR}/../include)
add_executable(out ${SOURCE})
set_target_properties(out PROPERTIES
		RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
