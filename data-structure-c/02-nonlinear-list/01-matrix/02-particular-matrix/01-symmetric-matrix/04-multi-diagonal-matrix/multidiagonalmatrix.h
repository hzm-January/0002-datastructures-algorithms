//
// Created by asus on 2019/7/23.
//

#ifndef DATA_STRUCTURE_C_MULTIDIAGONALMATRIX_H
#define DATA_STRUCTURE_C_MULTIDIAGONALMATRIX_H
#define MAX_SIZE 36
#define WIDTH 6
#define HEIGH 6

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int matrix[MAX_SIZE];
int last;
int band; //带宽(不包含主对角线)
bool insert(int value);

int find(int i, int j);

// 检查索引是否数组越界
void checkIndexOutOfBounds(int index);
// 检查数组是否已满
bool isFull();

#endif //DATA_STRUCTURE_C_MULTIDIAGONALMATRIX_H
