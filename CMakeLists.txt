cmake_minimum_required(VERSION 3.14)
project(fuzztest_calculator_cmake)

# GoogleTest requires at least C++17
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(fuzztest)

enable_testing()

include(GoogleTest)

fuzztest_setup_fuzzing_flags()

add_library(calc calculator.c)
add_executable(fuzztest_calculator_cmake fuzz_calculator.cpp)

target_link_libraries(fuzztest_calculator_cmake PUBLIC -fsanitize=address calc)

link_fuzztest(fuzztest_calculator_cmake)
gtest_discover_tests(fuzztest_calculator_cmake)
