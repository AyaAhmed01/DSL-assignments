cmake_minimum_required(VERSION 3.17)
project(DSL_assignments)

set(CMAKE_CXX_STANDARD 14)

add_executable(DSL_assignments
        "counting inversions/merge_sort_based.cpp"
        introsort/introsort.cpp
        introsort/quicksort.cpp
        introsort/stress.cpp
        "matrix multiplication/naive.cpp"
        "matrix multiplication/strassen.cpp"
        "matrix multiplication/stress.cpp")
