#include <bits/stdc++.h>
using namespace std;

void mergeSort(vector<int> &a, int l, int r)
{
   if (l >= r)
      return;
   int m = (l + r) / 2, i = l, j = m + 1;
   mergeSort(a, l, m), mergeSort(a, j, r);
   vector<int> temp(a.begin() + l, a.begin() + r + 1);
   for (int k = l; k <= r; k++)
      a[k] = j > r || (i <= m && temp[i - l] > temp[j - l]) ? temp[i++ - l] : temp[j++ - l];
}

int main()
{
   int n;
   cin >> n;
   vector<int> v(n);
   for(int i = 0; i < n; i++){
      cin >> v[i];
   }
   mergeSort(v, 0, n - 1);
   for (int x : v){
      cout << x << " ";
   }
      
}