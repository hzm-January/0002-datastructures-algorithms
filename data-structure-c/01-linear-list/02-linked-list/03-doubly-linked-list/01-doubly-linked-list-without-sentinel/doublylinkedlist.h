//
// Created by asus on 2019/5/28.
//

#ifndef DATA_STRUCTURE_C_DOUBLYLINKEDLIST_H
#define DATA_STRUCTURE_C_DOUBLYLINKEDLIST_H

#include "../../../linearlist.h"
typedef struct LinkedNodeStruct{
    int value;
    struct LinkedNodeStruct * next;
    struct LinkedNodeStruct * previous;
}LinkedNode;
LinkedNode * head;
bool checkIndex(int index);
bool checkHead();
void freeNode(LinkedNode * delNode);


#endif //DATA_STRUCTURE_C_DOUBLYLINKEDLIST_H
