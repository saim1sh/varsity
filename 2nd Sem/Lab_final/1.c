#include<stdio.h>
int main()
{
   int basic_sal;
   printf("Enter your salary: ");
   scanf("%d",&basic_sal);
   float gross_sal,dearness,house;
   dearness = basic_sal*.4;
   house = basic_sal*.2;
   gross_sal =basic_sal+dearness+house;
   printf("Finally gross salary is %.2f",gross_sal);

}