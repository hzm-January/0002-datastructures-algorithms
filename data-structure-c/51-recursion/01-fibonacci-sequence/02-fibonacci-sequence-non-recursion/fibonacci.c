//
// Created by hzm on 2019/6/12.
//

#include "fibonacci.h"

int fibonacci(int n) {
    int fibonacci[n];
    fibonacci[0] = 1;
    fibonacci[1] = 1;
    for (int i = 2; i < n; ++i) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }
    return fibonacci[n - 1];
}