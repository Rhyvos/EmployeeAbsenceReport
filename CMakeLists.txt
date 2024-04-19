cmake_minimum_required(VERSION 3.15)
set(CMAKE_C_COMPILER "/usr/bin/clang-18")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++-18")

project(EmployeeAbsenceReport)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -pedantic)

add_subdirectory(data)
add_subdirectory(loaders)
add_subdirectory(report)
add_subdirectory(business_logic)
add_subdirectory(application)


enable_testing()
add_subdirectory(tests)