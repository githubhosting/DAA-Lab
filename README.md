## Algorithm Lab 4th Sem

### [All Sorting Algorithms](https://www.interviewkickstart.com/learn/sorting-algorithms)

### [Merge Sort](https://www.interviewkickstart.com/learn/merge-sort)

### [Quick Sort](https://www.interviewkickstart.com/learn/quick-sort)

---

## Algorithms Code in C

<details><summary><b>Prims</b></summary>

```c
#include <stdio.h>
#include <stdlib.h>

#define infinity 9999
#define MAX 20

int G[MAX][MAX], spanning[MAX][MAX], n;

int prims();

int main()
{
    int i, j, total_cost;
    printf("Enter no. of vertices:");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &G[i][j]);
    total_cost = prims();
    printf("\nspanning tree matrix:\n");
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j < n; j++)
            printf("%d\t", spanning[i][j]);
    }
    printf("\n\nTotal cost of spanning tree = %d", total_cost);
    return 0;
}

int prims()
{
    int cost[MAX][MAX];
    int u, v, min_distance, distance[MAX], from[MAX];
    int visited[MAX], no_of_edges, i, min_cost, j;
    // create cost[][] matrix,spanning[][]
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            if (G[i][j] == 0)
                cost[i][j] = infinity;
            else
                cost[i][j] = G[i][j];
            spanning[i][j] = 0;
        }
    // initialise visited[],distance[] and from[]
    distance[0] = 0;
    visited[0] = 1;
    for (i = 1; i < n; i++)
    {
        distance[i] = cost[0][i];
        from[i] = 0;
        visited[i] = 0;
    }
    min_cost = 0;        // cost of spanning tree
    no_of_edges = n - 1; // no. of edges to be added
    while (no_of_edges > 0)
    {
        // find the vertex at minimum distance from the tree
        min_distance = infinity;
        for (i = 1; i < n; i++)
            if (visited[i] == 0 && distance[i] < min_distance)
            {
                v = i;
                min_distance = distance[i];
            }
        u = from[v];
        // insert the edge in spanning tree
        spanning[u][v] = distance[v];
        spanning[v][u] = distance[v];
        no_of_edges--;
        visited[v] = 1;
        // updated the distance[] array
        for (i = 1; i < n; i++)
            if (visited[i] == 0 && cost[i][v] < distance[i])
            {
                distance[i] = cost[i][v];
                from[i] = v;
            }
        min_cost = min_cost + cost[u][v];
    }
    return (min_cost);
}
```

</details>

<details><summary><b>Krushkal</b></summary>

```c
#include <stdio.h>
#include <stdlib.h>

int i, j, k, a, b, u, v, n, ne = 1;
int min, mincost = 0, cost[9][9], parent[9];

int find(int);
int uni(int, int);

void main()
{
    printf("Kruskal's algorithm in C\n");
    printf("========================\n");

    printf("Enter the no. of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    printf("The edges of Minimum Cost Spanning Tree are\n");
    while (ne < n)
    {
        for (i = 1, min = 999; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if (uni(u, v))
        {
            printf("%d edge (%d,%d) = %d\n", ne++, a, b, min);
            mincost += min;
        }

        cost[a][b] = cost[b][a] = 999;
    }

    printf("\nMinimum cost = %d\n", mincost);
}

int find(int i)
{
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j)
{
    if (i != j)
    {
        parent[j] = i;
        return 1;
    }

    return 0;
}
```

</details>

## Prims Input: 

Enter no. of vertices: 5

Enter the adjacency matrix:

0 1 2 0 0

1 0 2 0 4

2 2 0 3 0

0 0 3 0 2

0 4 0 2 0

## Krushkal Input:

Enter no. of vertices: 5

Enter the cost adjacency matrix:

0 1 2 0 1

1 0 3 0 1

2 3 0 6 5

0 0 6 0 0

1 1 5 0 0