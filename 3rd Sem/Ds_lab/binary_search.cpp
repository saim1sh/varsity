#include <bits/stdc++.h>
using namespace std;

// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Function to perform binary search
int binarySearch(int arr[], int n, int elem) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == elem) {
            return mid; // Element found
        } else if (arr[mid] < elem) {
            low = mid + 1; // Search in the right half
        } else {
            high = mid - 1; // Search in the left half
        }
    }
    return -1; // Element not found
}

int main() {
    int arr[10] = {9, 5, 6, 8, 3, 4, 2, 1, 78, 56};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sort the array
    bubbleSort(arr, n);
    cout << "Sorted array in ascending order: " << endl;
    for (auto boom : arr) {
        cout << boom << " ";
    }
    cout << "\n";

    // Input element to search
    cout << "Enter element to search: ";
    int elem;
    cin >> elem;

    // Perform binary search
    int index = binarySearch(arr, n, elem);
    if (index != -1) {
        cout << elem << " found at index " << index << endl;
    } else {
        cout << elem << " not found in array" << endl;
    }

    return 0;
}
