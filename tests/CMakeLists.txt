cmake_minimum_required(VERSION 3.15)

enable_testing()

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git 
    GIT_TAG v1.14.0
)
FetchContent_MakeAvailable(googletest)

file(GLOB_RECURSE TEST_SOURCES *.cpp)

add_executable(tests ${TEST_SOURCES})

target_link_libraries(tests gtest_main gmock_main Data BusinessLogic Loaders)

include(GoogleTest)
gtest_discover_tests(tests)

target_include_directories(tests PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/mocks
    ${CMAKE_SOURCE_DIR}/data/include
    ${CMAKE_SOURCE_DIR}/loaders/include
    ${CMAKE_SOURCE_DIR}/business_logic/include
)