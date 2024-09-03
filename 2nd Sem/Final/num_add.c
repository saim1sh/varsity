#include <stdio.h>

int main() {
    int a,i=0,sum = 0;
    scanf("%d",&a);
    while(a){
        sum += a%10;
        a = a/10;
        i++;
    }
    printf("Sum of the digits is %d ",sum);
    
    return 0;
}