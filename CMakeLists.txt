cmake_minimum_required(VERSION 3.10) # Specify minimum CMake version

project(TimeGauge VERSION 0.1.0) # Project name and version

set(SOURCE_FILES
  src/main.cpp
)

add_executable(TimeGauge ${SOURCE_FILES})

