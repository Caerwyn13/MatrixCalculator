cmake_minimum_required(VERSION 4.2)
project(MatrixAlgebra)

set(CMAKE_CXX_STANDARD 20)

add_executable(MatrixAlgebra main.cpp
        matrix.h
        Matrix.cpp
)
