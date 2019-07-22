//
// Created by asus on 2019/7/22.
//

#ifndef DATA_STRUCTURE_C_ORDINARYMATRIX_H
#define DATA_STRUCTURE_C_ORDINARYMATRIX_H
#define MAX_SIZE 20

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

//二维数组 行优先存储
int matrix[MAX_SIZE];
int last; // last index
int r; //row num
int columnNum; //column num
bool insert(int value);

int find(int row, int column);

#endif //DATA_STRUCTURE_C_ORDINARYMATRIX_H
