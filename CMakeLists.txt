cmake_minimum_required(VERSION 3.16)
project(tictactoe-cpp LANGUAGES CXX)

add_executable(tictactoe main.cpp)

set_target_properties(tictactoe PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

if (MSVC)
    target_compile_options(tictactoe PRIVATE /W4)
else()
    target_compile_options(tictactoe PRIVATE -Wall -Wextra -Wpedantic)
endif()
