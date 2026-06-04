#include <stdio.h>

#define MAX 10

int main()
{
    int n, a[MAX][MAX], indegree[MAX] = {0};
    int i, j, k;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            indegree[j] += a[i][j];
        }
    }

    printf("Topological Ordering:\n");

    for(k = 0; k < n; k++)
    {
        for(i = 0; i < n; i++)
        {
            if(indegree[i] == 0)
            {
                printf("%d ", i);

                indegree[i] = -1;

                for(j = 0; j < n; j++)
                {
                    if(a[i][j] == 1)
                    {
                        indegree[j]--;
                    }
                }
            }
        }
    }

    return 0;
}