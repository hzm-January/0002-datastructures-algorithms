//
// Created by asus on 2019/7/22.
//

#ifndef DATA_STRUCTURE_C_THREEDIAGONALMATRIX_H
#define DATA_STRUCTURE_C_THREEDIAGONALMATRIX_H
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 20
int matrix[MAX_SIZE];
int last;
int columnNum;
bool insert(int value);
int find(int row, int column);
#endif //DATA_STRUCTURE_C_THREEDIAGONALMATRIX_H
