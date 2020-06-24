cmake_minimum_required(VERSION 3.10)
project(matrix_and_vector)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

message("Cmake build type: ${CMAKE_BUILD_TYPE}")
set(CMAKE_BUILD_TYPE "Release")
# set(CMAKE_BUILD_TYPE "Debug")
message("Cmake build type after setting: ${CMAKE_BUILD_TYPE}")

# Debug mode ASAN flags
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -fsanitize=address -fsanitize=leak -fno-omit-frame-pointer -g")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall -Wextra -fsanitize=address -fsanitize=leak -fno-omit-frame-pointer -g")
set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -fsanitize=address -fsanitize=leak -fno-omit-frame-pointer")
set(CMAKE_MODULE_LINKER_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -fsanitize=address -fsanitize=leak -fno-omit-frame-pointer")

include_directories("${PROJECT_SOURCE_DIR}/include/")

add_executable(matrix_and_vector src/main.cpp src/Matrix.cpp src/Vector.cpp)