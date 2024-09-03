#include<stdio.h>
int main()
{
    int a;
    scanf("%d",&a);
    int num=(a%2==0)? printf("%d is even",a):printf("%d is odd",a);
    return 0;
}