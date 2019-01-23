cmake_minimum_required(VERSION 2.8.9)
project(CombSort)

include_directories(headers)

file(GLOB SOURCES "sources/*.cpp")

add_executable(CombSort ${SOURCES})
