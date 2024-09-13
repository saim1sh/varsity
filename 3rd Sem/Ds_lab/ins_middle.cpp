#include <bits/stdc++.h>
using namespace std;
int main()
{
   int arr[] = {1, 2, 3, 4, 5, 6, 7, 9, 10};
   int size = sizeof(arr) / sizeof(arr[0]);
   int n = size / 2;
   for (int i = 5; i > n; i--)
   {
      arr[i] = arr[i - 1];
   }
   arr[n] = 78;
   for (auto f : arr)
   {
      cout << f << " ";
   }
   return 0;
}