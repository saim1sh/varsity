#include <bits/stdc++.h>
using namespace std;
int linearSearch(int arr[], int size, int elem)
{
   for (int i = 0; i < size; i++)
   {
      if (arr[i] == elem)
      {
         return i;
      }
   }
   return -1;
}
int countOccurrences(int arr[], int size, int elem)
{
   int count = 0;
   for (int i = 0; i < size; i++)
   {
      if (arr[i] == elem)
      {
         count++;
      }
   }
   return count;
}
void deleteElement(int arr[], int &size, int elem)
{
   int idx = linearSearch(arr, size, elem);
   if (idx != -1)
   {
      for (int i = idx; i < size - 1; i++)
      {
         arr[i] = arr[i + 1];
      }
      size--;
   }
}

int main()
{
   int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 3, 3};
   int size = sizeof(arr) / sizeof(arr[0]);
   int elem = 3;
   int occurrences = countOccurrences(arr, size, elem);
   cout << "Occurrences of " << elem << ": " << occurrences << endl;
   deleteElement(arr, size, elem);
   occurrences = countOccurrences(arr, size, elem);
   cout << "Occurrences of " << elem << " after deletion: " << occurrences << endl;
   return 0;
}