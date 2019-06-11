//
// Created by Vincent Hou on 2019/5/27.
//

#ifndef DATA_STRUCTURE_C_LINKNODE_H
#define DATA_STRUCTURE_C_LINKNODE_H

typedef struct LinkNode {
    int value;
    struct LinkNode *next;
} LinkNode;

void freeNode(LinkNode *delNode);

#endif //DATA_STRUCTURE_C_LINKNODE_H
