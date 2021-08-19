cmake_minimum_required(VERSION 3.20)
project(Algorithms_Data_Structures_in_CPP)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Algorithms_Data_Structures_in_CPP
        FibonacciProblem.h
        GraphColoring.h
        Knapsack.h
        KnightTour.h
        LinkedList.h
        List.h
        main.cpp
        NQueensProblem.h)
