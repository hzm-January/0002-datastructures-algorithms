//
// Created by hzm on 2019/5/29.
//
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "polynomial.h"

int main(int argv, char *argc[]) {
    sentinel = (LinkNode *) malloc(sizeof(LinkNode));
    sentinel->next = NULL;
    sentinel->coefficient = 0;
    sentinel->exponent = 0;
    insert(1, 0);
    insert(1, 1);
    insert(2, 2);
    insert(3, 3);
    insert(4, 3);
    output();
    result(1);
    return 0;
}
