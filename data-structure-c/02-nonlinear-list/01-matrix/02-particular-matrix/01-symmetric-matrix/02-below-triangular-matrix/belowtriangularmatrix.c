//
// Created by asus on 2019/7/22.
//

#include "belowtriangularmatrix.h"

bool insert(int value) {
    matrix[last++] = value;
    return true;
}

int find(int row, int column) {
    int index = -1;
    if (row <= column) {
        index = (2 * columnNum - row + 1) * row / 2 + column;
    } else {
        index = (2 * columnNum - column + 1) * column / 2 + row;
    }
    return matrix[index];
}