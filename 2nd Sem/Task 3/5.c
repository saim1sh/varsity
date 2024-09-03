#include<stdio.h>
#include<math.h>
int main()
{
    float a, b, c;
    printf("Enter coefficients: ");
    scanf("%f %f %f", &a, &b, &c);
    float root1=(-b + sqrt(pow(b,2) - 4*a*c))/2*a; 
    float root2=(-b - sqrt(pow(b,2) - 4*a*c))/2*a; 
    printf("root1 : %.2f\n",root1);
    printf("root2 : %.2f\n",root2);
    return 0;
}