# ESP-IDF project CMakeLists.txt
cmake_minimum_required(VERSION 3.16)

# Set project name
set(PROJECT_NAME "lab6_2_multiple_files")

# Include ESP-IDF build system
include($ENV{IDF_PATH}/tools/cmake/project.cmake)

# Define the project
project(${PROJECT_NAME})