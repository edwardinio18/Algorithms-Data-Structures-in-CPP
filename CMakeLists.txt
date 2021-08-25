cmake_minimum_required(VERSION 3.20)
project(Algorithms-Data-Structures-in-CPP)

set(CMAKE_CXX_STANDARD 17)

add_executable(Algorithms-Data-Structures-in-CPP
        FibonacciProblem.h
        GraphColoring.h
        Knapsack.h
        KnightTour.h
        LinkedList.h
        List.h
        main.cpp
        NQueensProblem.h StackArray.h StackLinkedList.h QueueLinkedList.h BinarySearchTree.h Tree.h)
