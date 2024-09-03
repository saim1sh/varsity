#include <stdio.h>
int main()
{
   float num;
   scanf("%f", &num);
   if (num >= 0 && num <= 100)
   {
      if (num >= 80 && num <= 100)
      {
         printf("Grade: A+\n");
      }
      else if (num >= 75 && num <= 79)
      {
         printf("Grade: A\n");
      }
      else if (num >= 70 && num <= 74)
      {
         printf("Grade: A-\n");
      }
      else if (num >= 65 && num <= 69)
      {
         printf("Grade: B+\n");
      }
      else if (num >= 60 && num <= 64)
      {
         printf("Grade: B\n");
      }
      else if (num >= 55 && num <= 59)
      {
         printf("Grade: B-\n");
      }
      else if (num >= 50 && num <= 54)
      {
         printf("Grade: C+\n");
      }
      else if (num >= 45 && num <= 49)
      {
         printf("Grade: C\n");
      }
      else if (num >= 40 && num <= 44)
      {
         printf("Grade: D\n");
      }
      else
      {
         printf("Grade: F\n");
      }
   }
   else
   {
      printf("Invalid input! Please enter a number between 0 and 100.\n");
   }
}