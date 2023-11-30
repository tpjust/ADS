#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int vertices;
    struct Node** adjacencyList;
    int* visited;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->adjacencyList = (struct Node**)malloc(vertices * sizeof(struct Node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; ++i) {
        graph->adjacencyList[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void addEdge(struct Graph* graph, int start, int end) {
    struct Node* newNode = createNode(end);
    newNode->next = graph->adjacencyList[start];
    graph->adjacencyList[start] = newNode;

    // Uncomment the following lines if the graph is directed
    // newNode = createNode(start);
    // newNode->next = graph->adjacencyList[end];
    // graph->adjacencyList[end] = newNode;
}

void DFS(struct Graph* graph, int vertex) {
    printf("%d ", vertex);
    graph->visited[vertex] = 1;

    struct Node* temp = graph->adjacencyList[vertex];
    while (temp != NULL) {
        if (!graph->visited[temp->data]) {
            DFS(graph, temp->data);
        }
        temp = temp->next;
    }
}

int main() {
    int vertices, edges, start, end;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    struct Graph* graph = createGraph(vertices);

    for (int i = 0; i < edges; ++i) {
        printf("Enter edge (start end): ");
        scanf("%d %d", &start, &end);
        addEdge(graph, start, end);
    }

    printf("DFS Traversal starting from vertex 0: ");
    DFS(graph, 0);
    printf("\n");

    return 0;
}
