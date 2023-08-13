#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20

int parent[MAX_VERTICES];

// Find operation with path compression
int find(int vertex)
{
    if (parent[vertex] == -1)
        return vertex;
    return find(parent[vertex]);
}

// Union operation
void unionVertices(int root1, int root2)
{
    parent[root1] = root2;
}

void kruskal(int vertices, int cost[][MAX_VERTICES])
{
    int totalEdges = 0, minCost = 0;

    // Initialize parent array
    for (int i = 0; i < vertices; i++)
    {
        parent[i] = -1;
    }

    printf("Minimum Spanning Tree edges:\n");
    while (totalEdges < vertices - 1)
    {
        int min = 9999, a = -1, b = -1;

        // Find the minimum cost edge
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                if (find(i) != find(j) && cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        if (a != -1 && b != -1)
        {
            int rootA = find(a);
            int rootB = find(b);

            // Add edge to MST
            if (rootA != rootB)
            {
                printf("(%d, %d) - %d\n", a, b, min);
                unionVertices(rootA, rootB);
                minCost += min;
                totalEdges++;
            }

            cost[a][b] = cost[b][a] = 9999; // Mark the edge as visited
        }
    }

    printf("Minimum cost of spanning tree: %d\n", minCost);
}

int main()
{
    int vertices, cost[MAX_VERTICES][MAX_VERTICES];

    printf("Kruskal's algorithm in C\n");
    printf("========================\n");

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the cost adjacency matrix:\n");
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    kruskal(vertices, cost);

    return 0;
}
