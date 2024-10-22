#include <stdio.h>
#include <stdbool.h>

#define N 8  // Change this value to solve for different board sizes

// Function to print the solution
void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}

// Utility function to check if a queen can be placed on board[row][col]
bool isSafe(int board[N][N], int row, int col) {
    int i, j;

    // Check this row on the left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on the left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on the left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

// A recursive utility function to solve N Queen problem
bool solveNQUtil(int board[N][N], int col) {
    // Base case: If all queens are placed, return true
    if (col >= N)
        return true;

    // Consider this column and try placing this queen in all rows one by one
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;  // Place this queen in board[i][col]

            // Recur to place the rest of the queens
            if (solveNQUtil(board, col + 1))
                return true;

            board[i][col] = 0;  // Backtrack if placing the queen doesn't lead to a solution
        }
    }

    return false;  // If no place is possible in this column
}

// This function solves the N Queen problem using backtracking
bool solveNQ() {
    int board[N][N] = {0};  // Initialize the board with all 0s

    if (!solveNQUtil(board, 0)) {
        printf("Solution does not exist\n");
        return false;
    }

    printSolution(board);  // Print the solution
    return true;
}

int main() {
    solveNQ();
    return 0;
}
