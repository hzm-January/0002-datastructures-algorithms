//
// Created by asus on 2019/6/5.
//
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "../stack.h"
#include "matchbrackets.h"
int main(int argc, char *argv[]) {
    sentinel = (LinkedNode *) malloc(sizeof(LinkedNode));
    sentinel->value = -1;
    sentinel->next = NULL;
    char * demo = "((a+b)*c+12)*(c+f*(2+t))";
    printf("%s\n", demo);
//    printf("%d\n", true);
//    printf("%d\n", false);
    int i = 0;
    while (demo[i]) {
//        printf("%c",demo[i++]);
        if (demo[i] == '(') {
            push(1);
        }
        if (demo[i] == ')') {
            pop();
        }
        i++;
    }
}
