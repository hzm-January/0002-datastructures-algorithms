//
// Created by asus on 2019/8/6.
//
#include "childlink.h"

int main(int argc, char *argv[]) {

    // initialize
    initialize();
    // createTree
    createTreeByNodes(0, -1);
    createTreeByNodes(1, 0);
    createTreeByNodes(2, 1);
    createTreeByNodes(3, 1);
    destroy();
    return 0;
}
