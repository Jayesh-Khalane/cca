#include<stdio.h>

#define INT_MAX 999999

int n=4;
int dp[16][4];
int dist[10][10]={
    {0, 20, 42, 25},
    {20, 0, 30, 34},
    {42, 30, 0, 10},
    {25, 34, 10, 0}
};
int path[16][4];  // Array to store the path for each state

// Function to find the minimum cost path using Dynamic Programming and Bitmasking
int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1)  // All cities have been visited
        return dist[pos][0];    // Return to starting city

    int ans = INT_MAX;

    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    // Try visiting every other city
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {  // If the city has not been visited
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);

            if (newAns < ans) {
                ans = newAns;
                path[mask][pos] = city;  // Store the next city in the optimal path
            }
        }
    }

    return dp[mask][pos] = ans;
}

// Function to print the optimal path
void printPath() {
    int mask = 1, pos = 0;
    printf("Path: 0 -> ");  // Start from city 0

    // Traverse the path array to print the cities
    for (int i = 0; i < n - 1; i++) {
        int nextCity = path[mask][pos];
        printf("%d -> ", nextCity);
        mask |= (1 << nextCity);  // Mark the city as visited
        pos = nextCity;           // Move to the next city
    }

    printf("0\n");  // Finally return to the starting city
}

int main() {
    // Initialize dp array to -1
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }

    // Call the tsp function to find the shortest path
    printf("Shortest path cost is %d\n", tsp(1, 0));

    // Print the path
    printPath();

    return 0;
}
