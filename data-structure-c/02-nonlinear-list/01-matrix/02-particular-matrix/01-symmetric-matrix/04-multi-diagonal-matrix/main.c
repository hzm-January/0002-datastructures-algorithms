//
// Created by asus on 2019/7/23.
//
#include "multidiagonalmatrix.h"

int main(int argc, char *argv[]) {

    memset(matrix, 0, MAX_SIZE);
    band = 2;
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
    insert(11);
    insert(21);
    insert(31);
    insert(41);
    insert(51);
    insert(21);
    insert(22);
    insert(28);
    insert(24);
    insert(25);
    insert(111);
    insert(121);
    insert(131);
    insert(141);
    insert(151);
    insert(221);
    insert(222);
    insert(228);
    insert(224);
    insert(225);
    insert(1151);
    insert(1221);
    insert(1222);
    insert(1228);
    insert(1224);
    insert(1225);
    printf("%d\n", find(1, 2));
    printf("%d\n", find(3, 3));
    printf("%d\n", find(5, 3));
    return 0;

}