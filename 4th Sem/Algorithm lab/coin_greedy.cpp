#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int greedyCoinChange(vector<int>& coins, int amount) {
    sort(coins.rbegin(), coins.rend());
    int count = 0;
    for (int coin : coins) {
        while (amount >= coin) {
            amount -= coin;
            count++;
        }
    }
    return amount == 0 ? count : -1;
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << greedyCoinChange(coins, amount);
}
