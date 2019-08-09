//
// Created by asus on 2019/8/8.
//
#include "binarytreeconfirm.h"

int main(int avgc, char *argv[]) {
    pre_order_str = "ABHFDECKG";
    in_order_str = "HBDFAEKCG";
    BinaryTreeNode * node = creattree(pre_order_str, in_order_str, strlen(in_order_str));
    return 0;
}