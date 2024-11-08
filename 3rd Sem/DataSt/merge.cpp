#include <bits/stdc++.h>
using namespace std;


vector<int> merge(const vector<int> &l, const vector<int> &r) {
    int n = l.size(), m = r.size();
    vector<int> ans;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (l[i] < r[j]) {
            ans.push_back(l[i++]);
        } else {
            ans.push_back(r[j++]);
        }
    }
    while (i < n) {
        ans.push_back(l[i++]);
    }
    while (j < m) {
        ans.push_back(r[j++]);
    }
    return ans;
}
vector<int> merge_sort(int l, int r) {
    if (l == r) return {a[l]};
    int mid = l + (r - l) / 2;
    vector<int> left = merge_sort(l, mid);
    vector<int> right = merge_sort(mid + 1, r);
    return merge(left, right);
}

vector<int> a;

int main() {
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> ans = merge_sort(0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}