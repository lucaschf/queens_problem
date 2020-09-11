cmake_minimum_required(VERSION 3.15)
project(QueensProblem C)

set(CMAKE_C_STANDARD 99)

add_executable(QueensProblem main.c queens_problem.c queens_problem.h constants.h)