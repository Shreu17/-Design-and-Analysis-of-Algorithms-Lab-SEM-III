#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF 2147483647 // Using a large value to represent infinity

// Structure to represent a directed weighted edge
typedef struct {
    int u, v, w;
} Edge;

// Function to print the path recursively from source to the current node
void printPath(int parent[], int vertex) {
    if (parent[vertex] == -1) {
        printf("%d", vertex);
        return;
    }
    printPath(parent, parent[vertex]);
    printf("->%d", vertex);
}

int main() {
    int V, E;
    if (scanf("%d %d", &V, &E) != 2) return 0;

    // Allocate memory for edges dynamically
    Edge *edges = (Edge *)malloc(E * sizeof(Edge));
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    int src;
    scanf("%d", &src);

    // Arrays to store distances and predecessors
    long long *distance = (long long *)malloc((V + 1) * sizeof(long long));
    int *parent = (int *)malloc((V + 1) * sizeof(int));

    // Initialize distances and parents
    for (int i = 1; i <= V; i++) {
        distance[i] = INF;
        parent[i] = -1;
    }
    distance[src] = 0;

    // Relax all edges V - 1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (distance[u] != INF && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
                parent[v] = u;
            }
        }
    }

    // Check for negative-weight cycles
    bool hasNegativeCycle = false;
    for (int j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (distance[u] != INF && distance[u] + w < distance[v]) {
            hasNegativeCycle = true;
            break;
        }
    }

    if (hasNegativeCycle) {
        printf("Negative cycle detected\n");
    } else {
        // Print the output exactly matching CodeTantra format guidelines
        for (int i = 1; i <= V; i++) {
            if (i == src) continue;

            if (distance[i] == INF) {
                printf("%d INF None\n", i);
            } else {
                printf("%d %lld ", i, distance[i]);
                printPath(parent, i);
                printf("\n");
            }
        }
    }

    // Free dynamically allocated memory
    free(edges);
    free(distance);
    free(parent);

    return 0;
}
