//
// Created by hzm on 2019/5/27.
//

#include <stdlib.h>
#include <stdio.h>
#include "../../linknode.h"
#include "../../../linearlist.h"

LinkNode *tail = NULL;

int main(int argc, char *argv[]) {
    insert(0, 0);
    insert(1, 1);
    insert(2, 2);
    insert(3, 3);
    insert(2, 11);
    output();
    delete(2);
    output();
    delete(0);
    output();
    delete(2);
    output();
    printf("%d\n", search(1));
    return 0;
}