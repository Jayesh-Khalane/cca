#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 5  // Number of vertices in the graph

int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void printMST(int parent[], int graph[V][V]) {
    int minCost = 0;
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
        minCost += graph[i][parent[i]];
    }
    printf("Minimum cost of the spanning tree: %d\n", minCost);
}

void primMST(int graph[V][V]) {
    int parent[V];  // Array to store constructed MST
    int key[V];     // Key values used to pick minimum weight edge in cut
    bool mstSet[V]; // To represent set of vertices not yet included in MST

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX, mstSet[i] = false;
    }

    key[0] = 0;      // Include first vertex in MST
    parent[0] = -1;  // First node is always root of MST

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);  // Pick the minimum key vertex
        mstSet[u] = true;             // Add the picked vertex to the MST Set

        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u, key[v] = graph[u][v];
            }
    }

    printMST(parent, graph);  // Print the constructed MST
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0},
    };

    primMST(graph);

    return 0;
}
