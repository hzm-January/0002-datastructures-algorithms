//
// Created by hzm on 2019/5/29.
//

#ifndef DATA_STRUCTURE_C_SINGLYLINKEDLIST_H
#define DATA_STRUCTURE_C_SINGLYLINKEDLIST_H

typedef struct SinglyLinkedList_LinkedNode{
    int value;
    struct SinglyLinkedList_LinkedNode * next;
}LinkedNode;
LinkedNode * sentinel;
void freeNode(LinkedNode * delNode);
bool checkIndex(int index);
#endif //DATA_STRUCTURE_C_SINGLYLINKEDLIST_H
