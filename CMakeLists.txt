cmake_minimum_required(VERSION 3.10) # Specify minimum CMake version

project(YearGauge VERSION 0.1.0) # Project name and version

set(SOURCE_FILES
  src/main.cpp
)

add_executable(YearGauge ${SOURCE_FILES})

