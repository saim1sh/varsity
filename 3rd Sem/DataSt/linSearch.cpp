#include <bits/stdc++.h>
using namespace std;
int main()
{
   int arr[5] = {1, 2, 3, 4, 4};
   int cnt = 0;
   for (int i = 0; i < 5; i++)
   {
      cnt++;
      if (arr[i] == 4)
      {
         cout << i << "\n";
         break;
      }
   }
   cout << cnt << "\n";
   return 0;
}