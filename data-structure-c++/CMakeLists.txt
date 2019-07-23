cmake_minimum_required(VERSION 3.14)
project(data_structure_c__)

set(CMAKE_CXX_STANDARD 17)

add_executable(nonlinear_maxtrix_sparse
        02-nonlinear-list/01-matrix/03-sparse-matrix/sparsematrix.h
        02-nonlinear-list/01-matrix/03-sparse-matrix/sparsematrix.cpp
        02-nonlinear-list/01-matrix/03-sparse-matrix/main.cpp
        )