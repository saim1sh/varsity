#include <bits/stdc++.h>
using namespace std;
int main()
{
   int arr[8] = {1, 2, 3, 4, 5};
   int pos;
   cin >> pos;
   for (int i = 8; i > pos; i--)
   {
      arr[i] = arr[i - 1];
   }
   arr[pos] = 4;
   arr[pos + 1] = 9;
   for (auto n : arr)
   {
      cout << n << " ";
   }
   return 0;
}