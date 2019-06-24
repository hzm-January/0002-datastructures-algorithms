//
// Created by hzm on 2019/5/28.
//
#include <stdio.h>
#include <stdlib.h>
#include "../../../linearlist.h"
#include "doublylinkedlist.h"
LinkedNode * head =NULL;
int main(int argc, char * argv[]){
    insert(0, 1);
    insert(0, 2);
    insert(2, 4);
    insert(2, 5);
    insert(1, 3);
    output();
    delete(2);
    output();
    delete(3);
    output();
    delete(0);
    output();
    return 0;
}