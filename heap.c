#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the heap
#define MAX_HEAP_SIZE 100

// Structure for the binary heap
struct Heap {
    int arr[MAX_HEAP_SIZE];
    int size;
};

// Function to swap two values in the heap
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify the array (fix the heap property)
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

// Function to insert a new element into the heap
void insert(struct Heap* heap, int value) {
    if (heap->size == MAX_HEAP_SIZE) {
        printf("Heap is full. Cannot insert.\n");
        return;
    }

    // Insert the new element at the end
    int currentIndex = heap->size;
    heap->arr[currentIndex] = value;
    heap->size++;

    // Fix the heap property by comparing the new element with its parent
    while (currentIndex > 0 && heap->arr[currentIndex] < heap->arr[(currentIndex - 1) / 2]) {
        swap(&heap->arr[currentIndex], &heap->arr[(currentIndex - 1) / 2]);
        currentIndex = (currentIndex - 1) / 2;
    }
}

// Function to delete the minimum element from the heap
void deleteMin(struct Heap* heap) {
    if (heap->size == 0) {
        printf("Heap is empty. Cannot delete.\n");
        return;
    }

    // Replace the root with the last element
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;

    // Fix the heap property by heapifying from the root
    heapify(heap, 0);
}

// Function to print the elements of the heap
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

    // Insert elements into the heap
    insert(&heap, 3);
    insert(&heap, 2);
    insert(&heap, 1);
    insert(&heap, 5);
    insert(&heap, 4);

    // Print the heap
    printHeap(&heap);

    // Delete the minimum element
    deleteMin(&heap);

    // Print the heap after deletion
    printHeap(&heap);

    return 0;
}
