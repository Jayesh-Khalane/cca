#include <stdio.h>
#include <limits.h>

// Number of cities
#define N 4

// DP array to store the minimum cost for each subset of cities
int dp[16][N]; // 16 = 2^N where N = 4 (since there are 4 cities)

// Distance matrix (cost matrix)
int dist[N][N] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

// Function to implement TSP using Dynamic Programming + Bitmasking
int tsp(int mask, int pos) {
    // Base case: if all cities have been visited
    if (mask == (1 << N) - 1) {
        return dist[pos][0]; // Return the cost to go back to the starting city
    }

    // If already computed, return the stored value
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    // Initialize minimum cost as infinity
    int ans = INT_MAX;

    // Try to visit all cities and take the minimum cost path
    for (int city = 0; city < N; city++) {
        // If the city is not visited
        if ((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city); // Visit the city
            ans = (newAns < ans) ? newAns : ans;
        }
    }

    // Store and return the minimum cost
    return dp[mask][pos] = ans;
}

int main() {
    // Initialize DP array with -1
    for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = -1;
        }
    }

    // Start the TSP with mask = 1 (starting from city 0) and pos = 0
    int result = tsp(1, 0);

    // Print the result
    printf("The minimum cost of travelling all cities is: %d\n", result);

    return 0;
}
