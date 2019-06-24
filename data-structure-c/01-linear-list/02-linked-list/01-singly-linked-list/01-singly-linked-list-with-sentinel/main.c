//
// Created by hzm on 2019/5/29.
//
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../../linearlist.h"
#include "singlylinkedlist.h"

int main(int argc, char *argv[]) {
    sentinel = (LinkedNode *) malloc(sizeof(LinkedNode));
    sentinel->value = -1;
    sentinel->next = NULL;
    insert(0, 0);
    insert(0, 1);
    insert(2, 3);
    insert(2, 2);
    insert(0, 4);
    insert(0, 5);
    insert(0, 6);
    output();
    printf("length: %d\n", length());
//    delete(1);
//    output();
//    delete(0);
//    output();
//    delete(1);
    sort();
    output();
    reverse();
    output();
    printf("list is empty => %d\n", isEmpty());
    return 0;
}
