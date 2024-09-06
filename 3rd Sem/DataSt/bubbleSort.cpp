#include <bits/stdc++.h>
using namespace std;

void sorted(int arr[], int n)
{
   for (int i = 0; i < n - 1; i++)
   {
      for (int j = 0; j < n - 1 - i; j++)
      {
         if (arr[j] > arr[j + 1])
         {
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
         }
      }
   }
}

int main()
{
   int arr[] = {5, 4, 1, 2, 3};
   int n = sizeof(arr) / sizeof(arr[0]);
   sorted(arr, n);
   for (int i = 0; i < n; i++)
   {
      cout << arr[i] << " ";
   }

   return 0;
}