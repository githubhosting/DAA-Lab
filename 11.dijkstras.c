#include <stdio.h>
#include <stdlib.h>
#define INFINITY 9999
#define MAX 10

void dijkstra(int G[MAX][MAX], int n, int startnode);

int main()
{
	int G[MAX][MAX], i, j, n, u;
	printf("Enter no. of vertices: ");
	scanf("%d", &n);
	printf("\nEnter the adjacency matrix:\n");
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &G[i][j]);
	printf("\nEnter the starting node: ");
	scanf("%d", &u);
	dijkstra(G, n, u);
	return 0;
}

void dijkstra(int G[MAX][MAX], int n, int startnode)
{
	int cost[MAX][MAX], distance[MAX], from[MAX];
	int visited[MAX], count, min_distance, nextnode, i, j;
	// pred[] stores the predecessor of each node
	// count gives the number of nodes seen so far
	// create the cost matrix
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (G[i][j] == 0)
				cost[i][j] = INFINITY;
			else
				cost[i][j] = G[i][j];
	// initialise visited[], distance[] and from[]
	distance[startnode] = 0;
	visited[startnode] = 1;
	for (i = 0; i < n; i++)
	{
		distance[i] = cost[startnode][i];
		from[i] = startnode;
		visited[i] = 0;
	}
	count = 1;
	while (count < n - 1)
	{
		min_distance = INFINITY;
		// nextnode gives the node at minimum distance
		for (i = 0; i < n; i++)
			if (distance[i] < min_distance && !visited[i])
			{
				nextnode = i;
				min_distance = distance[i];
			}
		// check if a better path exists through nextnode
		visited[nextnode] = 1;
		for (i = 0; i < n; i++)
			if (!visited[i])
				if (min_distance + cost[nextnode][i] < distance[i])
				{
					distance[i] = min_distance + cost[nextnode][i];
					from[i] = nextnode;
				}
		count++;
	}
	// print the path and distance of each node
	for (i = 0; i < n; i++)
		if (i != startnode)
		{
			printf("\nDistance of node%d= %d", i, distance[i]);
			printf("\nPath= %d", i);
			j = i;
			do
			{
				j = from[j];
				printf("<-%d", j);
			} while (j != startnode);
		}
}
