cmake_minimum_required(VERSION 3.16)
project(Lab1)

add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/../mixUtils" "${CMAKE_BINARY_DIR}/mixUtils_build")

add_executable(main main.cpp)
target_link_libraries(main PRIVATE mix::utils)
