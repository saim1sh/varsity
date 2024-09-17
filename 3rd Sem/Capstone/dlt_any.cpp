#include <bits/stdc++.h>
using namespace std;
int main()
{
   int arr[5] = {9, 7, 4, 3, 8};
   int pos;
   cin >> pos;
   int arr_size = sizeof(arr) / sizeof(arr[0]);
   for (int i = pos; i < arr_size - 1; i++)
   {
      arr[i] = arr[i + 1];
   }
   for (int i = 0; i < arr_size - 1; i++)
   {
      cout << arr[i] << " ";
   }
   return 0;
}