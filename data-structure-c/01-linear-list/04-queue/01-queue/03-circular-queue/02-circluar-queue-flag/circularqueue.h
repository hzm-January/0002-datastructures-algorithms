//
// Created by hzm on 2019/6/24.
//

#ifndef DATA_STRUCTURE_C_CIRCULARQUEUE_H
#define DATA_STRUCTURE_C_CIRCULARQUEUE_H
#define MAX_SIZE 10

#include "../../../queue.h"
/**
 * true 上次操作为追加
 * false 上次操作为删除
 */
bool flag;
int queue[MAX_SIZE];
int head;
int tail;
#endif //DATA_STRUCTURE_C_CIRCULARQUEUE_H
