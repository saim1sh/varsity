#include <bits/stdc++.h>
using namespace std;
int main()
{
   int arr[5] = {1, 2, 3, 4};
   for (int i = 5; i > 0; i--)
   {
      arr[i] = arr[i - 1];
   }
   arr[0] = 76;
   for (auto n : arr)
   {
      cout << n << " " ;
   }
   cout << "\n";
   return 0;
}