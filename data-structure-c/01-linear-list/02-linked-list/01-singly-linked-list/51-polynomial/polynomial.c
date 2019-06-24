//
// Created by hzm on 2019/5/29.
//

#include "polynomial.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool insert(int coefficient, int exponent) {
    LinkNode *newNode = (LinkNode *) malloc(sizeof(LinkNode));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    LinkNode *p = sentinel;
    while (p->next != NULL) {
        if (p->next->exponent < newNode->exponent) {
            p = p->next;
        } else if (p->next->exponent == newNode->exponent) {
            p->next->coefficient += newNode->coefficient;
            return true;
        } else {
            break;
        }
    }
    newNode->next = p->next;
    p->next = newNode;
    return true;
}

void output() {
    printf("polynomail:\t");
    LinkNode *p = sentinel;
    while (p = p->next) {
        printf("%d*x^%d", p->coefficient, p->exponent);
        if (p->next != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

double result(int x) {
    LinkNode *p = sentinel;
    double count = 0;
    while (p = p->next) {
        double xExp = pow(x, p->exponent);
        count += p->coefficient * x * xExp;
        printf("%d*%d^%d", p->coefficient, x, p->exponent);
        if (p->next != NULL) {
            printf(" + ");
        }
    }
    printf(" = %lf\n", count);
    return count;
}