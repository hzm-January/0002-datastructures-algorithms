//
// Created by hzm on 2019/6/10.
//

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include "infixtosuffix.h"
#include "linedlistforoperator.h"


void inputExpression() {
    char *expression = (char *) malloc(100 * sizeof(char));
////    scanf("%s", expression);
////    printf("%s\n", expression);
////    char p = *expression;
////    printf("%c", p);
////
////    addLast('#');
////    int i = 0;
////    while (p = expression[i++]);
////    expression[i] = '#';
////    i = 0;
////    p = *expression;
    char temp = 0;
    int index = 0;
    expression[index++] = '#';
    while (scanf("%1c", &temp), temp!= '#') {
        if (temp == '\n') {
            continue;
        }
        expression[index++] = temp;
    }
    addLast('#');
    expression[index++]='#';
    expression[index++]='\0';
//    printf("%s\n", expression);
    char p = 0;
    int i = 1;
    while (p = expression[i++]) {
        switch (p) {
            case '#':
            case '-':
            case '+':
            case '*':
            case '/':
            case '(':
            case ')':
            case '%':
                //TODO:
                if (isp(getLast()) < icp(p)) {
                    addLast(p);
                } else if (isp(getLast()) > icp(p)) {
                    char operator = delLast();
                    if (operator != '(' && operator != ')') {
                        printf("%c", operator);
                    }
                }
                break;
            default:
                printf(" %c ", p);
        }
    }
}

/*
 * in stack priority
 */
int isp(char operator) {
    switch (operator) {
        case '#':
            return 0;
        case '-':
        case '+':
            return 3;
        case '*':
        case '/':
        case '%':
            return 5;
        case '(':
            return 1;
        case ')':
            return 6;
        default:
            printf("the operator does not match priority in stack");
    }
}

int icp(char operator) {
    switch (operator) {
        case '#':
            return 0;
        case '-':
        case '+':
            return 2;
        case '*':
        case '/':
        case '%':
            return 4;
        case '(':
            return 6;
        case ')':
            return 1;
        default:
            printf("the operator does not match priority in stack");
    }
}