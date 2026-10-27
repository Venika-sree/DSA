#include <stdio.h>
#define MAX 20
#define INF 10000000

int n;
int cost[MAX][MAX];

void dijkstra(int src, int dest) {
    int dist[MAX];
    int prev[MAX];
    int visited[MAX];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        prev[i] = -1;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < n; count++) {
        int u = -1;
        int minDist = INF;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] &&
                cost[u][v] != INF &&
                dist[u] != INF &&
                dist[u] + cost[u][v] < dist[v]) {

                dist[v] = dist[u] + cost[u][v];
                prev[v] = u;
            }
        }
    }

    if (dist[dest] == INF) {
        printf("No path exists from %d to %d.\n", src, dest);
        return;
    }

    int path[MAX];
    int length = 0;
    int current = dest;

    while (current != -1) {
        path[length++] = current;
        current = prev[current];
    }

    printf("Shortest path: ");

    for (int i = length - 1; i >= 0; i--) {
        printf("%d", path[i]);

        if (i > 0)
            printf(" -> ");
    }

    printf("\nShortest distance: %d\n", dist[dest]);
}

int main(void) {
    int src, dest;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Number of vertices must be between 1 and %d.\n", MAX);
        return 1;
    }

    printf("Enter cost adjacency matrix:\n");
    printf("Enter 0 for no edge (except diagonal entries).\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int value;
            scanf("%d", &value);

            if (i != j && value == 0)
                cost[i][j] = INF;
            else
                cost[i][j] = value;
        }
    }

    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &src);

    printf("Enter destination vertex (0 to %d): ", n - 1);
    scanf("%d", &dest);

    if (src < 0 || src >= n || dest < 0 || dest >= n) {
        printf("Invalid source or destination.\n");
        return 1;
    }

    dijkstra(src, dest);

    return 0;
}