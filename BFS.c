#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("This Queue is full\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("This Queue is empty\n");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int main()
{
    struct queue q;
    q.size = 400;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    // User-defined input for graph
    int size;
    printf("Enter the size of the graph: ");
    scanf("%d", &size);

    int a[size][size];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    int startNode;
    printf("Enter the starting node: ");
    scanf("%d", &startNode);

    // BFS Implementation
    int visited[size];
    for (int i = 0; i < size; i++)
    {
        visited[i] = 0;
    }

    printf("%d ", startNode);
    enqueue(&q, startNode);
    visited[startNode] = 1;

    while (!isEmpty(&q))
    {
        int node = dequeue(&q);
        for (int j = 0; j < size; j++)
        {
            if (a[node][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }

    free(q.arr); // Don't forget to free the allocated memory
    return 0;
}
