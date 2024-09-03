#include<stdio.h>
int sum_digits(int n){
   if(n==0){
      return 0;
   }
   int last_digit = n%10;
   int others = n/10;
   return sum_digits(others)+ last_digit;
}

int main(){
   int f;
   scanf("%d",&f);
   int a = sum_digits(f);
   printf("%d",a);
}