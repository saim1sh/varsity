#include <bits/stdc++.h>
using namespace std;

// Recursive Merge Sort function
void mergeSort(vector<int>& a, int l, int r) {
    if (l >= r) return; // Base case: If only one element, return

    int m = (l + r) / 2, i = l, j = m + 1; // Find middle index

    mergeSort(a, l, m), mergeSort(a, m + 1, r); // Recursively sort left & right halves

    // Temporary array to store merged result
    vector<int> t(a.begin() + l, a.begin() + r + 1);

    // Merge sorted halves back into original array
    for (int k = l; k <= r; k++)
        a[k] = j > r || (i <= m && t[i - l] < t[j - l]) ? t[i++ - l] : t[j++ - l];
}

int main() {
    vector<int> a = {38, 27, 43, 3, 9, 82, 10}; // Example array
    mergeSort(a, 0, a.size() - 1); // Sort the array

    // Print sorted array
    for (int x : a) cout << x << " ";
}