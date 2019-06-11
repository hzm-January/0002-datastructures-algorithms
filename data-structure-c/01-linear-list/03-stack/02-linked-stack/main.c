//
// Created by asus on 2019/5/31.
//
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "linkedstack.h"

int lastIndex = 0;

int main(int argc, char *argv[]) {
    sentinel = (LinkedNode *) malloc(sizeof(LinkedNode));
    sentinel->value = -1;
    sentinel->next = NULL;
    push(0);
    push(1);
    push(2);
    push(3);
    push(4);
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    return 0;
};
