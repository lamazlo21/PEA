cmake_minimum_required(VERSION 3.13)
project(PEA)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(PEA
        BST.cpp
        BST.h
        main.cpp
        Matrix.cpp
        Matrix.h
        Tests.cpp
        Tests.h
        TestyAutomatyczne.cpp
        TestyAutomatyczne.h Solution.cpp Solution.h BruteForce.cpp BruteForce.h)
