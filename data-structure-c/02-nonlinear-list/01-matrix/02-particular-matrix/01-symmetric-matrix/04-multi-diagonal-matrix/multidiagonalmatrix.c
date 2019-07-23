//
// Created by asus on 2019/7/23.
//

#include "multidiagonalmatrix.h"

bool insert(int value) {
    isFull();
    matrix[last++] = value;
    return true;
}

int find(int i, int j) {
    int prei = 0;
    int ini = 0;
    // 上部区域 第i行中第j列前 有j-1个元素
    if (i >= 1 && i <= band) {
        // 前i-1行的元素个数，第1行的元素个数为b+1，第2行的元素个数为b+2...第i-1行的元素个数为b+i，等差数列求和
        prei = (2 * band + i) * (i - 1) / 2;
        ini = j - 1;

    } else if (i > band && i < HEIGH - band + 1) {
        // 中部区域 第i行中第j列前 有j-i+b个元素
        // 前i-1行包含两部分，一部分是上部区域，一部分是中间区域
        // 上部区域band行，元素个数，第1行的元素个数为b+1，第2行的元素个数为b+2...第b行的元素个数为b+b，等差数列求和
        // 中间区域i-band-1行，元素个数，每一行有2b+1个元素
        prei = (3 * band + 1) * band / 2 + (2 * band + 1) * (i - band - 1);
        ini = j - i + band;
    } else if (i >= HEIGH - band + 1 && i <= HEIGH) {
        // 下部区域 前i-1行，包含三部分，上部分区域全部（b）行，中间区域全部（n-2b）行，下部分区域i-(n-b+1)行
        // 下部区域i-(n-b+1)行 设下部区域中自己的行数1<=k<b，k等价于i-(n-b+1)
        // 第1行，元素个数为 2*b+1-1
        // 第2行，元素个数为 2*b+1-2
        // 第k行，元素个数为 2*b+1-k
        // 最后的第i行，j列前面，有j-i+b个元素
        prei = (3 * band + 1) * band / 2 + (2 * band + 1) * (HEIGH - 2 * band) +
               (3 * band - i + HEIGH + 2) * (i - HEIGH + band - 1) / 2;
        ini = j - i + band;
    }
    int index = prei + ini; // 存放矩阵的数组中的索引位
    checkIndexOutOfBounds(index);
    return matrix[index];
}


void checkIndexOutOfBounds(int index) {
    if (index >= MAX_SIZE) {
        printf("index is out of bounds...\n");
        return;
    }
}

bool isFull() {
    if (last >= MAX_SIZE) {
        printf("the matrix is full");
        exit(0);
    }
}
