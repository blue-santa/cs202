# CMakeLists.txt

# Declare version number
cmake_minimum_required(VERSION 3.10)

# Name -- whatever the library is going to be called
project(LabStaticLibrary)

# ${PROJECT_NAME} = An automatically generated name, based on the declaration above
# STATIC = Instruct Cmake to make a static library
add_library(${PROJECT_NAME} STATIC
    LabStaticLibrary.cpp)

# Define a new project
# Useful for when there are larger projects with multiple directories
project(LabExample)

add_executable(LabExample
    main.cpp)

target_link_libraries(LabExample LabStaticLibrary)
