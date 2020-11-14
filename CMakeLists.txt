cmake_minimum_required(VERSION 3.10)

project(student_database_managment)

set(CMAKE_CXX_STANDART 11)

include_directories(${PROJECT_SOURCE_DIR})

file(GLOB CPP "*.cpp")

add_executable(${PROJECT_NAME} ${CPP})