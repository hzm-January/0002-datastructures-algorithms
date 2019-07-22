//
// Created by asus on 2019/7/22.
//
#include "ordinarymatrix.h"

int columnNum = 5;

int main(int argc, char *argv[]) {
    // initialize the array
    memset(matrix, 0, MAX_SIZE);
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    insert(1);
    insert(2);
    insert(8);
    insert(4);
    insert(5);
    printf("%d\n", find(1, 2));
    return 0;
}