#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct List {
    struct Node* head;
};

#define MAX 100

struct List adjacencyList[MAX];

void initializeGraph(int vertices) {
    for (int i = 0; i < vertices; i++) {
        adjacencyList[i].head = NULL;
    }
}

void addEdge(int start, int end) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = end;
    newNode->next = adjacencyList[start].head;
    adjacencyList[start].head = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = start;
    newNode->next = adjacencyList[end].head;
    adjacencyList[end].head = newNode;
}

void printGraph(int vertices) {
    printf("Adjacency List Representation:\n");
    for (int i = 0; i < vertices; i++) {
        struct Node* current = adjacencyList[i].head;
        printf("Vertex %d: ", i);
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    initializeGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (start end):\n");
    for (int i = 0; i < edges; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        addEdge(start, end);
    }

    printGraph(vertices);

    return 0;
}
