#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];  // Declare array after getting the size

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] > 0) {
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}