cmake_minimum_required(VERSION 3.15)

project(Report)

file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")

add_library(Report STATIC ${SOURCES} ${HEADERS})
set_target_properties(Report PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(Report PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/data/include
)
