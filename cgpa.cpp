#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n,i;
   cin >> n;
   float arr1[n];
   int arr2[n];
   cout << "Enter your courses point : " ;
   for (i=0; i<n; i++){
      cin >> arr1[i] ;
   }
   cout << "Enter your courses credit : " ;
   int sum=0;
   for (i=0; i<n; i++){
      cin >> arr2[i] ;
      sum += arr2[i];
   }
   float count=0;
   for (i=0; i<n; i++){
      count += arr1[i]*arr2[i];
   }
   float cgpa=count/sum;
   cout << "CGPA is " << setprecision(2) << cgpa << "\n";
   return 0;
}