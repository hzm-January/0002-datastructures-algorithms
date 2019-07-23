//
// Created by asus on 2019/7/22.
//

#include "threediagonalmatrix.h"
int columnNum = 5;
int main(int argc, char *argv[]){
    memset(matrix, 0, MAX_SIZE);
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    insert(1);
    insert(2);
    insert(8);
    insert(4);
    insert(5);
    printf("%d\n", find(1,2));
    printf("%d\n", find(3,3));
    return 0;
}
