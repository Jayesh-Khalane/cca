#include <stdio.h>

// Structure to hold the min and max values
struct MinMax {
    int min;
    int max;
};

// Function to find the min and max using divide and conquer
struct MinMax findMinMax(int arr[], int low, int high) {
    struct MinMax minmax, leftMinMax, rightMinMax;
    int mid;

    // Base case: If the array has only one element
    if (low == high) {
        minmax.min = arr[low];
        minmax.max = arr[low];
        return minmax;
   
