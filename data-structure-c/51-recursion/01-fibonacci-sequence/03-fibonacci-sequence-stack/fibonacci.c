//
// Created by hzm on 2019/6/12.
//

#include "fibonacci.h"

int fibonacci(int n) {
    if (n <= 2) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}