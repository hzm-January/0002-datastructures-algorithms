//
// Created by asus on 2019/8/23.
//

#include "heap.h"
#include <math.h>
#include "../../../../01-linear-list/04-queue/01-queue/02-linked-queue/linkedqueue.h"

// 初始化
Heap *heap_create(int maxsize) {
    Heap *heap = (Heap *) malloc(sizeof(int) * maxsize);
    heap->heap_current_size = 1; // 方便索引获取，下标从1开始
    heap->heap_max_size = 10;
    heap->heapArray = (int *) malloc(sizeof(int) * heap->heap_max_size);
    memset(heap->heapArray, -1, sizeof(int) * heap->heap_max_size);
    return heap;
}
// 插入
bool heap_insert(Heap *heap, int n) {
    if (heap_is_full()) {
        printf(" \\033[47;31m the heap is full \\033[0m");
    }
    // 1. 插入
    heap->heapArray[heap->heap_current_size++] = n;
    // 2. 堆化，从下往上
    heap_sift_up(heap, heap->heap_current_size - 1);
}
/**
 * 删除
 * @param n
 * @return
 */
bool heap_remove(Heap *heap, int n) {
    heap[1] = heap[--heap->heap_current_size];
//    heap[--heap_current_size] = -1;
    heap_sift_down(heap, 1, heap->heap_current_size - 1);
}
/**
 * 是否为空
 * @return 空true
 */
bool heap_is_empty(Heap *heap) {
    return heap->heap_current_size == 1;
}
/**
 * 是否已满
 * @return
 */
bool heap_is_full(Heap *heap) {
    return heap->heap_current_size == heap->heap_max_size;
}

/**
 * 堆化-从start到m，从上到下
 * @param start
 * @param m
 */
void heap_sift_down(Heap *heap, int start, int m) {
    int i = start;
    int temp = heap->heapArray[start];
    int j = i * 2;
    while (j <= m) {
        if (j < m && heap->heapArray[j] < heap->heapArray[j + 1]) j++;
        if (temp >= heap->heapArray[j]) break;
        else {
            heap->heapArray[i] = heap->heapArray[j];
            i = j;
            j = i * 2;
        }
    }
    heap->heapArray[i] = temp;
}

/**
 * 堆化-从start到0，从下到上
 * @param start
 */
void heap_sift_up(Heap *heap, int start) {
    int p = start;
    while ((p >> 1) > 0 && heap->heapArray[p] > heap->heapArray[p >> 1]) {
        heap_swap(heap, p, p / 2);
        p = p >> 1;
    }
}

/**
 * 交换
 * @param i
 * @param j
 */
void heap_swap(Heap *heap, const int i, const int j) {
    int temp = heap->heapArray[i];
    heap->heapArray[i] = heap->heapArray[j];
    heap->heapArray[j] = temp;
}

/**
 * 取i的最邻近的2的n次方的值
 * 如：输入6，返回8
 * 调用方式为 highestOneBit((n-1)<<1)
 */
int highestOneBit(unsigned int i) {
    // HD, Figure 3-1
    i |= (i >> 1);
    i |= (i >> 2);
    i |= (i >> 4);
    i |= (i >> 8);
    i |= (i >> 16);
    return i - (i >> 1);
}

// 遍历heap
void heap_print(Heap *heap, int end) {
    queue_init();
    enQueue(1);
    // 树高：将不是满二叉树的完全二叉树的节点数n，取邻近的2的幂次，再使用log(2)(n+1)计算出树高
//    int tree_hight = log10(highestOneBit((heap_current_size - 1) << 1)) / log10(2);
    // 树高：含有n个节点的完全二叉树的高度为 log(2)(n+1)向上取整
    int tree_hight = ceil(log10(heap->heap_current_size) / log10(2));
//    printf("tree_height: %d\n", tree_hight);
    for (int i = 1; i <= tree_hight; ++i) {
//        printf("tree_node_number: %lf\n", pow(2, i - 1));
        for (int j = 1; j <= pow(2, i - 1); ++j) {
            int n = deQueue();
            if (n > end) return;
            printf("%d\t", heap->heapArray[n]);
            enQueue(n << 1);
            enQueue((n << 1) + 1);
            if (j == pow(2, i - 1)) {
                printf("\n");
            }
        }
    }
}

// 堆排序
void heap_sort(Heap *heap) {
    int i = heap->heap_current_size - 1;
    while (i >= 1) {
        heap_swap(heap, 1, i--);
        heap_sift_down(heap, 1, i);
    }

}

void heap_distroy(Heap *heap) {
    if (heap != NULL) {
        if (heap->heapArray != NULL) {
            free(heap->heapArray);
            heap->heapArray = NULL;
        }
        free(heap);
        heap = NULL;
    }
}