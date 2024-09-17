#include <bits/stdc++.h>
using namespace std;

int main()
{
   int arr[6] = {9, 7, 4, 3, 8}; 
   int elem, pos;
   cin >> elem >> pos;
   for (int i = 5; i > pos; i--)
   {
      arr[i] = arr[i - 1];
   }
   arr[pos] = elem;
   for (auto n : arr)
   {
      cout << n << " ";
   }
   return 0;
}