//
// Created by asus on 2019/5/29.
//
#include "../stack.h"
#include "sequentialstack.h"
#include <stdio.h>
#include <stdlib.h>
int lastIndex = 0;
int main(int argv, char * argc[]){
    push(0);
    push(1);
    push(2);
    push(3);
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    return 0;
};