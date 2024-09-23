#include <bits/stdc++.h>
using namespace std;
void deleteTwoElements(int arr[], int &size, int element1, int element2)
{
   int i = 0;
   while (i < size)
   {
      if (arr[i] == element1 || arr[i] == element2)
      {
         for (int j = i; j < size - 1; j++)
         {
            arr[j] = arr[j + 1];
         }
         size--;
      }
      else
      {
         i++;
      }
   }
}
int main()
{
   int arr[] = {1, 2, 3, 4, 5, 2, 3, 4};
   int size = sizeof(arr) / sizeof(arr[0]);
   deleteTwoElements(arr, size, 2, 3);
   for (int i = 0; i < size; i++)
   {
      cout << arr[i] << " ";
   }
   return 0;
}