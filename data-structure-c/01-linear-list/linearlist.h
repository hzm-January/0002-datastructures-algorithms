//
// Created by hzm on 2019/5/27.
//

#ifndef DATA_STRUCTURE_C_LINEARLIST_H
#define DATA_STRUCTURE_C_LINEARLIST_H

#include <stdbool.h>

bool insert(int index, int value);
int delete(int i);
int deleteByVal(int value);
int search(int value);
int get(int i);
int set(int i, int value);
int length();
void output();
void sort();
void reverse();
bool isEmpty();
bool isFull();

#endif //DATA_STRUCTURE_C_LINEARLIST_H
