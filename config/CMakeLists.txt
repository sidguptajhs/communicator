#STANDARD COMMANDS
cmake_minimum_required(VERSION 3.10)
project(communicator)
set(CMAKE_CXX_STANDARD 14)



# MATH LIB
add_library(config server.cpp)
#install(TARGETS config EXPORT communicatorConfig)
#add_library(communicator::communicatorConfig ALIAS config)
