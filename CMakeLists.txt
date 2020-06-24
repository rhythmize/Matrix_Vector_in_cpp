cmake_minimum_required(VERSION 3.10)
project(Matrix_And_Vector)

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

file(GLOB_RECURSE source_files "${PROJECT_SOURCE_DIR}/src/*.cpp")
list(REMOVE_ITEM source_files "${PROJECT_SOURCE_DIR}/src/main.cpp")

add_library(${PROJECT_NAME} STATIC ${source_files})
set_target_properties(${PROJECT_NAME} PROPERTIES POSITION_INDEPENDENT_CODE ON)

add_executable(${PROJECT_NAME}_TEST ${PROJECT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(${PROJECT_NAME}_TEST ${PROJECT_NAME})

add_subdirectory(test)
