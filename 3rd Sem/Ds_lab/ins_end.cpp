#include<bits/stdc++.h>
using namespace std;
int main()
{
   int arr[5]={1,2,3,4};
   arr[5-1]=79;
   for(auto n:arr){
      cout<<n<<" ";
   }
   cout << "\n";
   return 0;
}