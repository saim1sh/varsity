#include <bits/stdc++.h>
using namespace std;
int main()
{
   int arr[] = {10, 5, 4, 10, 67, 45, 60};
   int arr_size = sizeof(arr) / sizeof(arr[0]);
   int elem = 10;
   for (int i = 0; i < arr_size; i++)
   {
      if (arr[i] == elem)
      {
         arr[i] = -1;
         break;
      }
   }
   for (auto n : arr)
   {
      cout << n << " ";
   }
   return 0;
}