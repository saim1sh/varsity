#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   cin >> n;
   int arr[n];
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }
   int *max = max_element(arr, arr + n);
   cout << *max << endl;

   return 0;
}