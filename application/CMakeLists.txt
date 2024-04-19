cmake_minimum_required(VERSION 3.15)

project(EmployeeAbsenceApp)

add_executable(EmployeeAbsenceApp main.cpp)
target_link_libraries(EmployeeAbsenceApp
    Data
    Loaders
    Report
    BusinessLogic
)
target_include_directories(EmployeeAbsenceApp PUBLIC
    ${CMAKE_SOURCE_DIR}/data/include
    ${CMAKE_SOURCE_DIR}/loaders/include
    ${CMAKE_SOURCE_DIR}/report/include
    ${CMAKE_SOURCE_DIR}/business_logic/include
)
