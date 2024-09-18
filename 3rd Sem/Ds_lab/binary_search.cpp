#include <bits/stdc++.h>
using namespace std;
int main()
{
   int arr[10] = {9, 5, 6, 8, 3, 4, 2, 1, 78, 56};
   for (int i = 0; i < 10; i++)
   {
      for (int j = 0; j < 10 - 1; j++)
      {
         if (arr[j] > arr[j + 1])
         {
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
         }
      }
   }
   cout << "Sorted array in ascending order: " << endl;
   for (auto boom : arr)
   {
      cout << boom << " ";
   }
   cout << "\n";
   cout << "Enter element to search: ";
   int avg = 10 / 2;
   int elem;
   cin >> elem;
   int low = 0;
   int high = 10 - 1;
   while (low <= high)
   {
      int mid = (low + high) / 2;
      if (arr[mid] == elem)
      {
         cout << elem << " found at index " << mid << endl;
         break;
      }
      else if (arr[mid] < elem)
      {
         low = mid + 1;
      }
      else
      {
         high = mid - 1;
      }
   }
   if (low > high)
   {
      cout << elem << " not found in array" << endl;
   }
   return 0;
}

// In binary search ,time complexity is O(log(n)) which is far better as compare to binary search
// time complexity which is O(n).
