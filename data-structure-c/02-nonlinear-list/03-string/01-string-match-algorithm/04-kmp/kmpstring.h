//
// Created by asus on 2019/7/30.
//

#ifndef DATA_STRUCTURE_C_KMPSTRING_H
#define DATA_STRUCTURE_C_KMPSTRING_H

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// 失效函数
int * next;
// initialize
void initialize(char * pattern);
// destroy
void destroy();
// find
int find(char *target, char *pattern);
#endif //DATA_STRUCTURE_C_KMPSTRING_H
