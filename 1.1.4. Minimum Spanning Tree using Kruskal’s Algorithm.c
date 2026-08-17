#include <stdio.h>
#include <stdlib.h>
#include <limits.h>



void kruskalMST(int **cost, int V)
{
	int parent[V];
	int i, j;

	for(i = 0; i < V; i++)
		parent[i] = i;

	int edgeCount = 0;
	int minCost = 0;

	while(edgeCount < V - 1)
	{
		int min = INT_MAX;
		int u = -1, v = -1;

		for(i = 0; i < V; i++)
		{
		for(j = i + 1; j < V; j++)
			{
				if(cost[i][j] < min)
				{
					 min = cost[i][j];
					u = i;
					v = j;
				}
			}
		}

        int ru = u;
}
