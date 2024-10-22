#include <stdio.h>
#include <limits.h>

#define N 4  // Number of cities

// Function to calculate the lower bound for a node (partial solution)
int calculateBound(int graph[N][N], int path[], int level) {
    int bound = 0;
    bool visited[N] = {false};

    // Mark the nodes in the current path as visited
    for (int i = 0; i < level; i++)
        visited[path[i]] = true;

    // Calculate the lower bound by adding minimum edge costs from unvisited nodes
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            int minEdge = INT_MAX;
            for (int j = 0; j < N; j++) {
                if (i != j && !visited[j]) {
                    if (graph[i][j] < minEdge)
                        minEdge = graph[i][j];
                }
            }
            bound += minEdge;
        }
    }

    return bound;
}

// Function to print the final solution path and cost
void printSolution(int finalPath[], int minCost) {
    printf("Minimum cost: %d\n", minCost);
    printf("Path: ");
    for (int i = 0; i < N; i++) {
        printf("%d -> ", finalPath[i]);
    }
    printf("%d\n", finalPath[0]);  // Complete the cycle
}

// Recursive function to solve TSP using Branch and Bound
void tspBranchAndBound(int graph[N][N], int path[], int visited[], int level, int currentCost, int* minCost, int finalPath[]) {
    if (level == N) {
        currentCost += graph[path[level - 1]][path[0]];  // Add the cost to return to the starting city

        if (currentCost < *minCost) {
            *minCost = currentCost;
            for (int i = 0; i < N; i++) {
                finalPath[i] = path[i];
            }
        }
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            int bound = calculateBound(graph, path, level);

            // Prune the search if the lower bound + current cost is already greater than the minCost
            if (currentCost + bound < *minCost) {
                path[level] = i;
                visited[i] = 1;

                tspBranchAndBound(graph, path, visited, level + 1, currentCost + graph[path[level - 1]][i], minCost, finalPath);

                visited[i] = 0;  // Backtrack
            }
        }
    }
}

int main() {
    // Example graph (cost matrix)
    int graph[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int path[N] = {0};         // To store the current path
    int finalPath[N] = {0};    // To store the final best path
    int visited[N] = {0};      // To track visited cities
    visited[0] = 1;            // Start from the first city

    int minCost = INT_MAX;     // Initialize the minimum cost as infinity

    tspBranchAndBound(graph, path, visited, 1, 0, &minCost, finalPath);

    printSolution(finalPath, minCost);  // Print the final solution

    return 0;
}
