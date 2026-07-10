cmake_minimum_required(VERSION 3.10)
project(001_market_imbalance_calculator)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(001_market_imbalance_calculator main.cpp)

target_compile_options(001_market_imbalance_calculator PRIVATE
    -Wall -Wextra -pedantic -O0 -g
    -fsanitize=address,undefined)

target_link_options(001_market_imbalance_calculator PRIVATE
    -fsanitize=address,undefined)

