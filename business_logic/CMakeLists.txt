cmake_minimum_required(VERSION 3.15)

project(BusinessLogic)

file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")

add_library(BusinessLogic STATIC ${SOURCES} ${HEADERS})
set_target_properties(BusinessLogic PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(BusinessLogic PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/data/include
)
