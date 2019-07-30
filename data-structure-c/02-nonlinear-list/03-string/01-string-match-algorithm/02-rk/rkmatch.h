//
// Created by asus on 2019/7/29.
//

#ifndef DATA_STRUCTURE_C_RKMATCH_H
#define DATA_STRUCTURE_C_RKMATCH_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * 字母26进制对应字典
 */
//enum SYSTEM_DICTIONARY {
//    a, b, c, d, e, f, g, h, i, j, k, l, m, n
//};
int *hash_dictionary; // 目标串子串hashcode字典
int *power_dictionary;// 进制幂次字典
int pattern_hash_code; // 模式串hashcode

/**
 * 字符串RK匹配
 * @param target 主串（目标串）
 * @param pattern 模式串
 * @return
 */
int find(char *target, char *pattern);

/**
 * hash 函数
 * @param target
 */
void substringhashcodedictionary(char *string, int len);

/***
 * 字母表字典
 * @return
 */
int *alphabetDictionary();

/**
 * 进制基数幂次字典
 */
void systempowerdictionary(int len);

/**
 * 初始化
 */
void initialize();
void destroy(); //释放资源
int patternhashcode(char *pattern);

#endif //DATA_STRUCTURE_C_RKMATCH_H
