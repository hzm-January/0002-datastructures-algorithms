//
// Created by asus on 2019/7/30.
//

#ifndef DATA_STRUCTURE_C_BMMATCH_H
#define DATA_STRUCTURE_C_BMMATCH_H
#define BCD_SIZE 256

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
// 坏字符字典
int *bad_character_dictionary;
int *suffix;
bool *prefix;

// 初始化
void initialize(char *pattern);

// 释放资源
void destroy();

// 生成坏字符字段
void generatebcd(char *pattern);
// 生成好前缀规则辅助的两个数组（一个好后缀的后缀在模式串中可匹配的起始位置，一个好后缀的后缀可匹配模式串前缀的bool值）
void generatesuffixprefix(char *pattern);

// find
int find(char *target, char *pattern);

#endif //DATA_STRUCTURE_C_BMMATCH_H
