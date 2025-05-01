#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int count = 0; // Global counter

void solve(vector<int>& coins, int i, int target, vector<int>& path) {
    if (target == 0) {
        count++;
        for (int coin : path) cout << coin << " ";
        cout << endl;
        return;
    }

    for (int j = i; j < coins.size(); j++) {
        if (coins[j] > target) break;
        path.push_back(coins[j]);
        solve(coins, j, target - coins[j], path); // reuse same coin
        path.pop_back();
    }
}

int main() {
    vector<int> coins = {1, 2, 5};
    int target = 5;

    sort(coins.begin(), coins.end());
    vector<int> path;

    solve(coins, 0, target, path);

    cout << "Total ways: " << count << endl;

    return 0;
}
