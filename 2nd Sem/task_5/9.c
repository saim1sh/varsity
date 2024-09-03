#include<stdio.h>
int main()
{
    float i;
    int n,c=0;
    for(n=1;n<=6;n++)
    {
        scanf("%f",&i);
        if(i>0)
        {
            c++;
        }
    }
    printf("%d valores positivos\n",c);
}
