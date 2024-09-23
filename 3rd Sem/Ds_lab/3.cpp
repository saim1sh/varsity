#include <bits/stdc++.h>
using namespace std;
void deleteThreeElements(int arr[], int &size, int pos1, int pos2, int pos3)
{
   if (pos1 >= 0 && pos1 < size && pos2 >= 0 && pos2 < size && pos3 >= 0 && pos3 < size)
   {
      int positions[] = {pos1, pos2, pos3};
      for (int i = 0; i < 3; i++)
      {
         int pos = positions[i];
         for (int j = pos; j < size - 1; j++)
         {
            arr[j] = arr[j + 1];
         }
         size--;
      }
   }
}
int main()
{
   int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
   int size = sizeof(arr) / sizeof(arr[0]);
   deleteThreeElements(arr, size, 1, 3, 5);
   for (int i = 0; i < size; i++)
   {
      cout << arr[i] << " ";
   }
   return 0;
}