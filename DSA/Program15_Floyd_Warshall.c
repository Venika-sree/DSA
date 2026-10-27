#include <stdio.h>
#define MAX 20
#define INF 10000000

int main(void) {
    int n;
    int cost[MAX][MAX];

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

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (cost[i][k] != INF &&
                    cost[k][j] != INF &&
                    cost[i][k] + cost[k][j] < cost[i][j]) {
                    cost[i][j] = cost[i][k] + cost[k][j];
                }
            }
        }
    }

    printf("\nAll-Pairs Shortest Distance Matrix:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (cost[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", cost[i][j]);
        }
        printf("\n");
    }

    return 0;
}