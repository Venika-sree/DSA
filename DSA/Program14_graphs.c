#include <stdio.h>
#define MAX 20

int adj[MAX][MAX];
int visited[MAX];
int n;

void BFS(int start) {
    int queue[MAX];
    int front = 0, rear = 0;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal: ");

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    printf("\n");
}

void DFS(int current) {
    visited[current] = 1;
    printf("%d ", current);

    for (int i = 0; i < n; i++) {
        if (adj[current][i] == 1 && !visited[i])
            DFS(i);
    }
}

int main(void) {
    int start;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Number of cities must be between 1 and %d.\n", MAX);
        return 1;
    }

    printf("Enter adjacency matrix (%d x %d):\n", n, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
    }

    printf("Enter starting city (0 to %d): ", n - 1);
    scanf("%d", &start);

    if (start < 0 || start >= n) {
        printf("Invalid starting city.\n");
        return 1;
    }

    BFS(start);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal: ");
    DFS(start);
    printf("\n");

    return 0;
}