#include <bits/stdc++.h>
using namespace std;
void deleteElement(int arr[], int size, int element)
{
   int i;
   for (i = 0; i < size; i++)
   {
      if (arr[i] == element)
      {
         for (int j = i; j < size - 1; j++)
         {
            arr[j] = arr[j + 1];
         }
         size--;
         break;
      }
   }
}
void deleteAllOccurrences(int arr[], int &size, int element)
{
   int i = 0;
   while (i < size)
   {
      if (arr[i] == element)
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
   int arr[] = {1, 2, 3, 4, 5, 2, 2};
   int size = sizeof(arr) / sizeof(arr[0]);
   deleteAllOccurrences(arr, size, 2);
   for (int i = 0; i < size; i++)
   {
      cout << arr[i] << " ";
   }
   return 0;
}