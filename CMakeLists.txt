cmake_minimum_required(VERSION 3.17)
project(ex6 C)

set(CMAKE_C_STANDARD 99)

add_executable(ex6 main.c ex6.h queue.h Utils.h Utils.c ex6.c queue.c)