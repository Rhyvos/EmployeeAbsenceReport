cmake_minimum_required(VERSION 3.15)

project(Loaders)

file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")

add_library(Loaders STATIC ${SOURCES} ${HEADERS})
set_target_properties(Loaders PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(Loaders PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/data/include
)
