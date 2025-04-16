#include <bits/stdc++.h>
using namespace std;

struct Kit
{
    int weight;
    int value;
};

void bfs(int S, vector<vector<int>> &boom, int location)
{
    queue<int> q;
    vector<bool> visited(location + 1, false);
    q.push(S);
    visited[S] = true;
    cout << "BFS Visit Order: ";
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (int neighbor : boom[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << "\n";
}

void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    cout << "Sorted list: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << "\n";
}

bool binarySearch(const vector<int> &arr, int key)
{
    int left = 0, right = arr.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == key)
            return true;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}

int knapsack(int W, const vector<Kit> &kits)
{
    vector<int> dp(W + 1, 0);
    for (const Kit &k : kits)
    {
        for (int w = W; w >= k.weight; --w)
        {
            dp[w] = max(dp[w], dp[w - k.weight] + k.value);
        }
    }
    return dp[W];
}

void displayKits(vector<Kit> &kits, int capacity)
{
    cout << "Robot Capacity: " << capacity << "\n";
    cout << "Kits (weight, value):" << "\n";
    for (const Kit &k : kits)
    {
        cout << k.weight << ", " << k.value << "\n";
    }
}

int main()
{
    int N, R;
    cin >> N >> R;

    vector<vector<int>> boom(N + 1);
    for (int i = 0; i < R; ++i)
    {
        int u, v;
        cin >> u >> v;
        boom[u].push_back(v);
        boom[v].push_back(u);
    }

    int S;
    cin >> S;

    int K;
    cin >> K;

    vector<Kit> kits(K);
    vector<int> weights(K), values(K);
    for (int i = 0; i < K; ++i)
    {
        cin >> kits[i].weight >> kits[i].value;
        weights[i] = kits[i].weight;
        values[i] = kits[i].value;
    }

    int W;
    cin >> W;

    bfs(S, boom, N);
    bubbleSort(weights);
    bubbleSort(values);
    bool found = binarySearch(values, 50);
    cout << "Kit with value 50 exists: " << (found ? "Yes" : "No") << "\n";
    displayKits(kits, W);
    int maxVal = knapsack(W, kits);
    cout << "Maximum value bot can carry: " << maxVal << "\n";

    return 0;
}