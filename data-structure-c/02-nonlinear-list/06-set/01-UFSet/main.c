//
// Created by asus on 2019/8/22.
//
#include "ufset.h"

int main() {
    ufset_init(parent);
    ufset_union(parent, 1, 2);
    ufset_union(parent, 4, 3);
    ufset_union(parent, 5, 6);
    ufset_union(parent, 8, 9);
    ufset_weight_union(parent, 1, 9);
    return 0;
}