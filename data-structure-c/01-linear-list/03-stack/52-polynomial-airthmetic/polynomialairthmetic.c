//
// Created by asus on 2019/6/6.
//

#include "polynomialairthmetic.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void input() {
    char str[100];
    while (scanf("%99s", str), strcmp(str, "#") != 0) {
        if (strcmp(str, "+") == 0
            || strcmp(str, "-") == 0
            || strcmp(str, "*") == 0
            || strcmp(str, "/") == 0) {
            doOperator(str);
        } else {
            addOperand(atof(str));
        }
    }
}

void doOperator(char *operator) {
    if (isEmpty()) {
        printf(" the right operand is NULL ");
        exit(1);
    }
    double right = getOperand();
    if (isEmpty()) {
        printf(" the left operand is NULL ");
        exit(1);
    }
    double left = getOperand();
    if (strcmp(operator, "+") == 0) {
        addOperand(left + right);
    } else if (strcmp(operator, "-") == 0) {
        addOperand(left - right);
    } else if (strcmp(operator, "*") == 0) {
        addOperand(left * right);
    } else if (strcmp(operator, "/") == 0) {
        if (right == 0) {
            printf(" the right operand is illegal ");
        } else {
            addOperand(left / right);
        }
    }
}

double addOperand(double operand) {
    return append(operand);
}

double getOperand() {
    return removeLast();
}
