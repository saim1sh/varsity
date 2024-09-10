#include <bits/stdc++.h>
using namespace std;

int main()
{
   int arr[5] = {4, 8, 9, 3, 7};
   int n = sizeof(arr) / sizeof(arr[0]);
   int index_dlt;
   cin >> index_dlt;
   if (index_dlt >= 0 && index_dlt < n)
   {
      for (int i = index_dlt; i < n - 1; i++)
      {
         arr[i] = arr[i + 1];
      }
      for (int i = 0; i < n - 1; i++)
      {
         cout << arr[i] << " ";
      }
   }
   else
   {
      cout << "Invalid index" << endl;
   }
   return 0;
}