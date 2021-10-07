cmake_minimum_required(VERSION 3.14)
project(UniquePtr)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY "https://github.com/google/googletest.git"
    GIT_TAG release-1.11.0
)

FetchContent_MakeAvailable(googletest)

# Debug config
set(DEBUG_FLAGS -Wall -Werror -Wpedantic -Wextra -g)

# Main function
add_executable(main main.cpp)
target_compile_options(main PUBLIC ${DEBUG_FLAGS})

# tests
enable_testing()
add_executable(unitTests ut.cpp)
target_compile_options(unitTests PUBLIC ${DEBUG_FLAGS})
target_link_libraries(unitTests gtest_main)
include(GoogleTest)
gtest_discover_tests(unitTests)
