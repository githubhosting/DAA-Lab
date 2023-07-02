// DFS traversal of a graph using stack as an auxiliary data structure

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

int cost[MAX_VERTICES][MAX_VERTICES], i, j, k, n, stk[MAX_VERTICES], top, v, visit[MAX_VERTICES], visited[MAX_VERTICES];

int main()
{
    int m;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    printf("\nEDGES:\n");
    for (k = 1; k <= m; k++)
    {
        scanf("%d %d", &i, &j);
        cost[i][j] = 1;
    }
    printf("Enter the initial vertex to traverse from: ");
    scanf("%d", &v);

    printf("DFS ORDER OF VISITED VERTICES: ");
    printf("%d ", v);
    visited[v] = 1;
    k = 1;
    while (k < n)
    {
        for (j = n; j >= 1; j--)
        {
            if (cost[v][j] != 0 && visited[j] != 1 && visit[j] != 1)
            {
                visit[j] = 1;
                stk[top] = j;
                top++;
            }
        }
        v = stk[--top];
        printf("%d ", v);
        k++;
        visit[v] = 0;
        visited[v] = 1;
    }
    return 0;
}