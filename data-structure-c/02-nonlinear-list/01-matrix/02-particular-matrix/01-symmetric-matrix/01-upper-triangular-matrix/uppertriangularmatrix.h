//
// Created by asus on 2019/7/22.
//

#ifndef DATA_STRUCTURE_C_UPPERTRIANGULARMATRIX_H
#define DATA_STRUCTURE_C_UPPERTRIANGULARMATRIX_H

#define MAX_SIZE 20

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
int matrix[MAX_SIZE];
int last;
bool insert(int value);
int find(int row, int column);

#endif //DATA_STRUCTURE_C_UPPERTRIANGULARMATRIX_H
