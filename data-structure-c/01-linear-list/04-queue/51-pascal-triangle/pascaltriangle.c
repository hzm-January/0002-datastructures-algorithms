//
// Created by hzm on 2019/6/24.
//

#include "pascaltriangle.h"

void pascalTriangle(int n) {
    LinkNode *secondNode = (LinkNode *) malloc(sizeof(LinkNode));
    secondNode->value = 1;
    secondNode->next = NULL;
    LinkNode *firstNode = (LinkNode *) malloc(sizeof(LinkNode));
    firstNode->value = 1;
    firstNode->next = secondNode;
    sentinel = (LinkNode *) malloc(sizeof(LinkNode));
    sentinel->value = -1;
    sentinel->next = firstNode;
    // 中间变量
    int s = 0; //位移元素
    for (int i = 0; i <= n; ++i) {
        enQueue(0); //行分割标识
        printf("\n");
        for (int j = 0; j <= i + 2; ++j) {
            int k = deQueue();
            enQueue(k + s);
            s = k;
            if (j != i + 2) {
                printf("%d\t", s);
            }
        }
    }
}