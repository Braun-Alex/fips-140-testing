cmake_minimum_required(VERSION 3.20)
project(Testing_Of_Random_Generators)

set(CMAKE_CXX_STANDARD 23)
set(HEADERS functions.h tests.h)
set(SOURCES main.cpp functions.cpp tests.cpp)

add_subdirectory(testing/googletest)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

target_link_libraries(${PROJECT_NAME} gtest_main gtest)