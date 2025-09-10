
#include <stdio.h>
#include <limits.h>
#define V 4

void floydWarshall(int graph[][V], int n)
{
    int dist [V][V];
    int i, j, k;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            dist[i][j] = graph[i][j];

    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    printf("The shortest path between every pair of vertices is:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (dist[i][j] == INT_MAX)
                printf("INF\t");
            else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int graph[V][V];
    int n, i, j;

    printf("Enter the number of vertices in the graph (maximum %d): ", V);
    scanf("%d", &n);

    printf("Enter the elements of the graph matrix (enter 'INF' for infinity):\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            char input[10];
            scanf("%s", input);
            if (input[0] == 'I' && input[1] == 'N' && input[2] == 'F')
                graph[i][j] = INT_MAX;
            else
                graph[i][j] = atoi(input);
        }
    }

    floydWarshall(graph, n);
    return 0;
}










