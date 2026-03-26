#include <stdio.h>

void kruskals();

int cost[10][10], m, n, i, j;
int count, k, u, v, parent[10], t[10][10];

void union_ij(int i, int j);
int find(int);

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost of adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);

            if (i != j && cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    kruskals();
    return 0;
}

void kruskals() {
    count = 0;
    k = 0;
    int sum = 0;

    for (i = 0; i < n; i++)
        parent[i] = i;

    while (count != n - 1) {
        int min = 999;

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        int root_u = find(u);
        int root_v = find(v);

        if (root_u != root_v) {
            t[k][0] = u;
            t[k][1] = v;
            k++;
            count++;
            sum += min;

            union_ij(root_u, root_v);
        }

        cost[u][v] = cost[v][u] = 999;
    }

    printf("\nSpanning Tree:\n");
    for (i = 0; i < n - 1; i++) {
        printf("%d -> %d\n", t[i][0], t[i][1]);
    }

    printf("Total cost: %d\n", sum);
}

void union_ij(int i, int j) {
    if (i < j)
        parent[j] = i;
    else
        parent[i] = j;
}

int find(int v) {
    while (parent[v] != v) {
        v = parent[v];
    }
    return v;
}
