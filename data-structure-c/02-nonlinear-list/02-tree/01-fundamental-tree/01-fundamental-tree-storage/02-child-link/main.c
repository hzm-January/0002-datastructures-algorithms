//
// Created by asus on 2019/8/6.
//
#include "childlink.h"

int main(int argc, char *argv[]) {

    // initialize
    initialize();
    // save
    save(0, -1);
    save(1, 0);
    save(2, 1);
    save(3, 1);
    destroy();
    return 0;
}
