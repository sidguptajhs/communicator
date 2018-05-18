#STANDARD COMMANDS
cmake_minimum_required(VERSION 3.10)
project(sample)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)



function(set_from_env_or_default var default_value)
    if ("$ENV{${var}}" STREQUAL "")
        set("${var}" "${default_value}" PARENT_SCOPE)
    else()
        set("${var}" "$ENV{${var}}" PARENT_SCOPE)
    endif()
endfunction(set_from_env_or_default)



# Using BOOST
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
set(Boost_DEBUG ON)

set_from_env_or_default("BOOST_ROOT" "/spare/local/siddhartha/venv-infra/boost/1.66.0-gcc5-c++14-release-multi-libicu54.1")
set_from_env_or_default("BOOST_LIBRARYDIR" "/spare/local/siddhartha/venv-infra/boost/1.66.0-gcc5-c++14-release-multi-libicu54.1/lib")
set_from_env_or_default("BOOST_INCLUDEDIR" "/spare/local/siddhartha/venv-infra/boost/1.66.0/include")
find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})


# CONFIG LIBRARY
add_subdirectory("config")



set(COMMUNICATOR_COMMON_LIBS config)

add_executable(communicator_client main.cpp)
target_compile_definitions(communicator_client PUBLIC COMMUNICATOR_CLIENT_MODE)
target_link_libraries(communicator_client
                      ${COMMUNICATOR_COMMON_LIBS}
                      ${Boost_LIBRARIES})

# SAMPLE2 EXE -> ENGLISHLIB -> FEATURELIB
add_executable(communicator_service main.cpp)
target_link_libraries(communicator_service
                      ${COMMUNICATOR_COMMON_LIBS}
                      ${Boost_LIBRARIES})