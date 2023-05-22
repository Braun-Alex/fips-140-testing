cmake_minimum_required(VERSION 3.20)
project(testing_of_random_generators)

set(CMAKE_CXX_STANDARD 23)
set(SOURCES main.cpp functions.h functions.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
