cmake_minimum_required(VERSION 3.10)
project(run_tests)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

include_directories("${PROJECT_SOURCE_DIR}/include/")

file(GLOB_RECURSE source_files "${PROJECT_SOURCE_DIR}/src/*.cpp")

ADD_EXECUTABLE(${PROJECT_NAME} ${source_files})

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${GTEST_BOTH_LIBRARIES} Matrix_And_Vector)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})