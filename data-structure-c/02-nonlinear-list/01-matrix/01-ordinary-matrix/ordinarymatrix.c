//
// Created by asus on 2019/7/22.
//

#include "ordinarymatrix.h"
bool insert(int value){
    matrix[last++] = value;
    return true;
}

int find(int row, int column){
    int index = row * columnNum + column;
    if (index >= MAX_SIZE) {
        return -1;
    }
    return matrix[index];
}