#include "doublestack.h"

//
// Created by asus on 2019/6/5.
//
int lowIndex = -1;
int highIndex = MAX_SIZE;
int main(int argv, char * argc[]){
    push(0, 0);
    push(0, 1);
    push(0, 2);
    push(1, 10);
    push(1, 9);
    push(1, 8);
    output(0);
    output(1);
    pop(0);
    pop(1);
}
