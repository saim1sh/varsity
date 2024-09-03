#include<stdio.h>
int main()
{
   int n,reminder,reversed=0,original;
   printf("Enter a number: ");
   scanf("%d",&n);
   original=n;
   if( n>99999){
      printf("Invalid");
      return 1;
   }
   while(n != 0){
      reminder=n%10;
      reversed =reversed*10 +reminder;
      n /=10;
   }
   printf("Reversed num is %d \n",reversed);
   if( original==reversed){
      printf("original and reversed are equal");
   }
   else{
      printf("original and reversed are not equal");

   }
}