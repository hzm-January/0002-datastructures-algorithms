//
// Created by asus on 2019/8/22.
//

#include "ufset.h"

void ufset_init(int s[]) {
    // 初始化，每个结点都作为一颗独立树的根
    memset(s, -1, sizeof(int) * SIZE);
}

int ufset_find(int pt[], int x) {
    while (pt[x] >= 0) x = pt[x];
    return x;
}

// 递归实现
//int ufset_find(int s[], int x) {
//    if (parent[x] < 0) return x;
//    else ufset_find(s, parent[x]);
//}

void ufset_union(int pt[], int root1, int root2) {
    int irp = ufset_find(pt, root1);
    int jrp = ufset_find(pt, root2);
    if (irp != jrp) {
        pt[root1] += pt[root2];
        pt[root2] = root1;
    }
}

void ufset_weight_union(int pt[], int root1, int root2) {
    int irp = ufset_find(pt, root1);
    int jrp = ufset_find(pt, root2);
    if (irp != jrp) {
        if (pt[root1] > pt[root2]) {
            pt[root1] += pt[root2];
            pt[root2] = root1;
        } else {
            pt[root2] += pt[root1];
            pt[root1] = root2;
        }
    }
}