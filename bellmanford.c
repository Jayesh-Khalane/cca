#include <stdio.h>
#include <limits.h>

// Function to implement Bellman-Ford algorithm
void BellmanFord(int graph[][3], int V, int E, int src) {
    int dist[V]; // Distance array to store shortest path estimates

    // Step 1: Initialize distances from source to all other vertices as INFINITE
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    // Step 2: Relax all edges |V| - 1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph[j][0];
            int v = graph[j][1];
            int weight = graph[j][2];
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Step 3: Check for negative-weight cycles
    for (int j = 0; j < E; j++) {
        int u = graph[j][0];
        int v = graph[j][1];
        int weight = graph[j][2];
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Graph contains negative-weight cycle\n");
            return;
        }
    }

    // Print the distance array
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

int main() {
    // Number of vertices and edges
    int V = 5;  // Number of vertices
    int E = 8;  // Number of edges

    // Each edge has (u, v, weight)
    // Edge list representation: {source, destination, weight}
    int graph[][3] = {
        {0, 1, -1}, {0, 2, 4},
        {1, 2, 3}, {1, 3, 2},
        {1, 4, 2}, {3, 2, 5},
        {3, 1, 1}, {4, 3, -3}
    };

    // Call Bellman-Ford algorithm with source vertex as 0
    BellmanFord(graph, V, E, 0);

    return 0;
}
