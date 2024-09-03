#include <stdio.h>
int main()
{
   int n;
   scanf("%d", &n);
   int fact = 1;
   if (n >= 0)
   {
      while (n > 1)
      {
         fact *= n;
         n--;
      }
      printf("Factorial is %d", fact);
   }
   else
   {
      printf("Factorial is not defined for negative numbers");
   }
}