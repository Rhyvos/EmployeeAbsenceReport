cmake_minimum_required(VERSION 3.15)

project(Data)

file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")

add_library(Data STATIC ${SOURCES} ${HEADERS})


set_target_properties(Data PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(Data PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)