#include<stdio.h>
int main()
{
    int i,n,a[50];
    scanf("%d",&n);
    a[0]=0;
    a[1]=1;
    for(i=0;i<=n;i++)
    {
        a[i+2]=a[i]+a[i+1];
    }
    for(i=0;i<n;i++)
    {
        printf(" %d",a[i]);
    }
    printf("\n");
}
