# Define CMake's minimum version (must-do) and the project's name and supported languages
cmake_minimum_required(VERSION 3.8.2)
project(heartbeat_pomo)

get_board_id(my_board uno)

add_arduino_executable(heartbeat_pomo ${my_board} headway_demo.cpp)

add_arduino_library(led_lib ${my_board} neopixel/Adafruit_NeoPixel.cpp)
target_include_directories(led_lib PUBLIC neopixel)
link_arduino_library(heartbeat_pomo led_lib ${my_board})

upload_arduino_target(heartbeat_pomo "${my_board}" /dev/cu.usbmodem1441)