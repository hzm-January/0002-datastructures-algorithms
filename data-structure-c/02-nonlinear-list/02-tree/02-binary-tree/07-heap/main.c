//
// Created by asus on 2019/8/23.
//
#include "heap.h"


int main() {


    Heap *heap = heap_create(10);
    heap_insert(heap, 1);
    heap_insert(heap, 2);
    heap_insert(heap, 3);
    heap_insert(heap, 8);
    heap_insert(heap, 9);
    heap_print(heap, heap->heap_current_size - 1);
//    heap_remove(1);
//    heap_remove(1);
    heap_sort(heap);
    printf("\n");
    for (int i = 1; i < heap->heap_current_size; ++i) {
        printf("%d\t", heap->heapArray[i]);
    }
    return 0;
}