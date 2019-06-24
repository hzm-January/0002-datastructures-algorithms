//
// Created by hzm on 2019/5/31.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "staticlist.h"
//LinkNode * list[MAX_SIZE];
int main(int argc, char *argv[]) {
//    LinkNode *list[10];
//    list[0] = (LinkNode *) malloc(sizeof(LinkNode));
//    list[0]->next = 12;
//    printf("%d", list[0]->next);
    initial();
    insert(0, 0);
    insert(1, 3);
    insert(1, 1);
    insert(2, 2);
    output();
//    delete(1);
    delete(2);
    output();
    delete(1);
    output();
    delete(1);
    output();
    delete(1);
    output();
//    delete(2);
//    delete(3);

}
