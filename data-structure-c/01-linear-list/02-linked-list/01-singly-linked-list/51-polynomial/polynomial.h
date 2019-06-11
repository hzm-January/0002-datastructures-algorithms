//
// Created by asus on 2019/5/29.
//

#ifndef DATA_STRUCTURE_C_POLYNOMIAL_H
#define DATA_STRUCTURE_C_POLYNOMIAL_H

#include <stdbool.h>

typedef struct POLYNOMIAL_LINKNODE {
    int coefficient;
    int exponent;
    struct POLYNOMIAL_LINKNODE * next;
} LinkNode;
LinkNode * sentinel;
bool insert(int coefficient, int exponent);
void output();
int delete(int coefficient, int exponent);
double result(int x);

#endif //DATA_STRUCTURE_C_POLYNOMIAL_H
