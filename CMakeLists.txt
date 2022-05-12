cmake_minimum_required(VERSION 3.22)
project(chess)

set(CMAKE_CXX_STANDARD 14)

add_executable(chess main.cpp cmake-build-debug/Chessboard.cpp cmake-build-debug/Chessboard.h)
