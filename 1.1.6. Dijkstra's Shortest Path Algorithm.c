#include <limits.h> 
#include <stdio.h>
#define MAX 20
int V, E;
int graph[MAX][MAX];
#define INFINITY 99999

void dijkstra(int G[MAX][MAX], int n, int startnode) {
	// write your code here
  int distance[MAX], pred[MAX], visited[MAX];
    int count, mindistance, nextnode, i, j;

    // Initialize based on the main() function's matrix layout
    for (i = 1; i <= n; i++) {
        visited[i] = 0;
        if (i == startnode) {
            distance[i] = 0;
            pred[i] = startnode;
        } else if (G[startnode][i] > 0 && G[startnode][i] != INFINITY) {
            distance[i] = G[startnode][i];
            pred[i] = startnode;
        } else {
            distance[i] = INFINITY;
            pred[i] = 0;
        }
    }

    visited[startnode] = 1;
    count = 1;

    while (count < n) {
        mindistance = INFINITY;

        for (i = 1; i <= n; i++) {
            if (distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i];
