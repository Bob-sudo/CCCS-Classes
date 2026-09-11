cmake_minimum_required(VERSION 3.31)
project(se_project VERSION 1.0 LANGUAGES CXX)
set(SOURCES
  src/main.cpp
)

add_executable(program ${SOURCES})

add_custom_target(r
  ./program)

add_custom_target(c
  make clean)
