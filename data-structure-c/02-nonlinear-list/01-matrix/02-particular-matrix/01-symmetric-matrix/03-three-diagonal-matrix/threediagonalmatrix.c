//
// Created by asus on 2019/7/22.
//

#include "threediagonalmatrix.h"

bool insert(int value) {
    matrix[last++] = value;
    return true;
}

/**
 * 1<=row<=n
 * 1<=j<=n
 */
int find(int row, int column) {
    int index = 3 * (row - 1) - 1 + column - row + 1;
    return matrix[index];
}