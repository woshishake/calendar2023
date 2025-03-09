cmake_minimum_required(VERSION 3.0)

project(CALENDER)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall")

include_directories(${CMAKE_SOURCE_DIR}/include)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})

add_executable(calendar main.cpp  src/scheduleManage.cpp src/schedule.cpp src/login.cpp src/user.cpp src/md5.cpp)