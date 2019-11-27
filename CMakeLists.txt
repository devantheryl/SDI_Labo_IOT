cmake_minimum_required(VERSION 3.0)
project(HelloBt) 
set(CMAKE_AUTOMOC ON) 
find_package(Qt5 COMPONENTS Core Bluetooth) 
add_executable(${PROJECT_NAME} main.cpp) 
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Bluetooth