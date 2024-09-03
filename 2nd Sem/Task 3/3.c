#include<stdio.h>
#include<ctype.h>

int main()
{
    char n;
    printf("Enter a Charecter : ");
    scanf("%c",&n);
    int ch=isalpha(n)?printf("%c is charecter",n):printf("%c is not charecter",n);
}