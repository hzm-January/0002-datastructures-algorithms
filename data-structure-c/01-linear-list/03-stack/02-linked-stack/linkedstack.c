//
// Created by hzm on 2019/5/31.
//
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "linkedstack.h"

bool push(int value){
    return insert(lastIndex++, value);
}

int pop(){
    return delete(--lastIndex);
}