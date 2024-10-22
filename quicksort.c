#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for quicksort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choose the last element as pivot
    int i = low - 1;  // Index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// QuickSort function
void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);  // Sort elements before partition
        quick_sort(arr, pi + 1, high);  // Sort elements after partition
    }
}

int main() {
    int arr[] = {33, 10, 55, 71, 29, 5, 47, 88, 12};  // Hardcoded array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call quicksort on the array
    quick_sort(arr, 0, n - 1);

    // Print sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
