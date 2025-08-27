#include <iostream>
#include <algorithm> // For swap
using namespace std;

int Partition(int A[], int l, int h) {
    int pivot = A[l]; 
    int i = l, j = h;
    do {
        do { i++; } while (A[i] <= pivot && i < h); // Ensure `i` stays within bounds
        do { j--; } while (A[j] > pivot);
        if (i < j) swap(A[i], A[j]); // Correct condition for swapping
    } while (i < j);
    swap(A[l], A[j]);
    return j;
}

void QuickSort(int A[], int l, int h) {
    if (l < h) {
        int j = Partition(A, l, h);
        QuickSort(A, l, j);   // Recursive call for left part
        QuickSort(A, j + 1, h); // Recursive call for right part
    }
}

int main() {
    int A[] = {10, 100, 200, 1, 20, 289, 9292, 28292, INT32_MAX}; // Add sentinel value
    int n = sizeof(A) / sizeof(A[0]) - 1; // Ignore sentinel in size
    QuickSort(A, 0, n - 1);
    
    // Display sorted array
    for (int i = 0; i < n - 1; i++) {
        cout << A[i] << " ";
    }
    return 0;
}
