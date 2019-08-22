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
    if (row >= column) {
        index = (1 + row) * row / 2 + column;
    } else {
        index = (1 + column) * column / 2 + row;
    }
    return matrix[index];
}
