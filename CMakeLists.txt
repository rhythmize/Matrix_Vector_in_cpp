cmake_minimum_required(VERSION 3.16)
project(matrix_and_vector)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

include_directories("${PROJECT_SOURCE_DIR}/include/")

add_executable(matrix_and_vector src/main.cpp src/Matrix.cpp src/Vector.cpp)