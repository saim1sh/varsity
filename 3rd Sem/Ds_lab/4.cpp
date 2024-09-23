#include <bits/stdc++.h>
using namespace std;
void deleteElements(int arr[], int &size, int elem1, int elem2)
{
   int newSize = size;
   for (int i = 0; i < newSize; i++)
   {
      if (arr[i] == elem1)
      {
         for (int j = i; j < newSize - 1; j++)
         {
            arr[j] = arr[j + 1];
         }
         newSize--;
         i--;
      }
      if (arr[i] == elem2)
      {
         for (int j = i; j < newSize - 1; j++)
         {
            arr[j] = arr[j + 1];
         }
         newSize--;
         i--;
      }
   }
   size = newSize;
   int count1 = 0, count2 = 0;
   for (int i = 0; i < newSize; i++)
   {
      if (arr[i] == elem1)
      {
         count1++;
      }
      if (arr[i] == elem2)
      {
         count2++;
      }
   }
   if (count1 == 0)
   {
      cout << "Element " << elem1 << " can not be deleted as it is not exist." << endl;
   }
   if (count2 == 0)
   {
      cout << "Element " << elem2 << " can not be deleted as it is not exist." << endl;
   }
}

int main()
{
   int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
   int size = sizeof(arr) / sizeof(arr[0]);
   int elem1 = 3, elem2 = 6;
   deleteElements(arr, size, elem1, elem2);
   for (int i = 0; i < size; i++)
   {
      cout << arr[i] << " ";
   }
   cout << endl;
   return 0;
}