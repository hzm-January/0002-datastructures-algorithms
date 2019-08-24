//
// Created by asus on 2019/8/23.
//

#ifndef DATA_STRUCTURE_C_HEAP_H
#define DATA_STRUCTURE_C_HEAP_H
//#define HEAP_MAX_SIZE 10

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct HEAP {
    // 堆
    int *heapArray;
    // 堆当前的大小
    int heap_current_size;
    int heap_max_size;
} Heap;


/**
 * 初始化
 */
Heap *heap_create(int maxsize);

/**
 * heap
 * @param heap
 */
void heap_distroy(Heap *heap);
/**
 * 插入
 * @param n
 * @return
 */
bool heap_insert(Heap *heap, int n);
/**
 * 删除
 * @param n
 * @return
 */
bool heap_remove(Heap *heap, int n);
/**
 * 是否为空
 * @return 空true
 */
bool heap_is_empty();
/**
 * 是否已满
 * @return
 */
bool heap_is_full();

/**
 * 堆化-从start到m，从上到下
 * @param start
 * @param m
 */
void heap_sift_down(Heap *heap, int start, int m);

/**
 * 堆化-从start到0，从下到上
 * @param start
 */
void heap_sift_up(Heap *heap, int start);

/**
 * 交换
 * @param i
 * @param j
 */
void heap_swap(Heap *heap, const int i, const int j);

/**
 * 层级遍历，从1开始，到end
 * @param end
 */
void heap_print(Heap *heap, int end);

/**
 * 堆排序
 */
void heap_sort(Heap *heap);

#endif //DATA_STRUCTURE_C_HEAP_H
