cmake_minimum_required(VERSION 3.16)
project(uniq-cpp)
set(CMAKE_CXX_STANDARD 20)
set(BOOST_MIN_VERSION "1.66.0")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

find_package(Boost ${BOOST_MIN_VERSION} COMPONENTS
        context coroutine date_time thread system program_options regex REQUIRED)

# Boost.Coroutine2 (the successor of Boost.Coroutine)
# (1) doesn't even exist in old Boost versions and
# (2) isn't supported by ASIO, yet.
add_definitions(-DBOOST_COROUTINES_NO_DEPRECATION_WARNING)

link_directories(${Boost_LIBRARY_DIRS})
include_directories(${Boost_INCLUDE_DIRS})

set(base_DEPS ${CMAKE_DL_LIBS} ${Boost_LIBRARIES})

set(base_SOURCES main.cpp)

add_executable(coroutine ${base_SOURCES})

target_link_libraries(coroutine ${base_DEPS})

set_target_properties(
        coroutine PROPERTIES
        FOLDER Bin
        OUTPUT_NAME boost-coroutine
)
