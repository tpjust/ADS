#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100

struct Heap {
    int arr[MAX_HEAP_SIZE];
    int size;
};

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct Heap* heap, int index) {
    int smallest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < heap->size && heap->arr[leftChild] < heap->arr[smallest]) {
        smallest = leftChild;
    }

    if (rightChild < heap->size && heap->arr[rightChild] < heap->arr[smallest]) {
        smallest = rightChild;
    }

    if (smallest != index) {
        swap(&heap->arr[index], &heap->arr[smallest]);
        heapify(heap, smallest);
    }
}

void insert(struct Heap* heap, int value) {
    if (heap->size == MAX_HEAP_SIZE) {
        printf("Heap is full. Cannot insert.\n");
        return;
    }

    int currentIndex = heap->size;
    heap->arr[currentIndex] = value;
    heap->size++;

    while (currentIndex > 0 && heap->arr[currentIndex] < heap->arr[(currentIndex - 1) / 2]) {
        swap(&heap->arr[currentIndex], &heap->arr[(currentIndex - 1) / 2]);
        currentIndex = (currentIndex - 1) / 2;
    }
}

void deleteMin(struct Heap* heap) {
    if (heap->size == 0) {
        printf("Heap is empty. Cannot delete.\n");
        return;
    }

    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;

    heapify(heap, 0);
}

void printHeap(struct Heap* heap) {
    printf("Heap: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Heap heap;
    heap.size = 0;

    int numElements, element;

    printf("Enter the number of elements to insert into the heap: ");
    scanf("%d", &numElements);

    printf("Enter the elements to insert into the heap:\n");
    for (int i = 0; i < numElements; i++) {
        scanf("%d", &element);
        insert(&heap, element);
    }

    printf("Heap after insertion: ");
    printHeap(&heap);

    deleteMin(&heap);

    printf("Heap after deletion of minimum element: ");
    printHeap(&heap);

    return 0;
}
