#include <stdio.h>
int main()
{
    int f;
    printf("Ener temperature in Fahrenheit : ");
    scanf("%d", &f);
    printf("Temperature in Celcius is : %.2f\n", (float)(f - 32) * 5 / 9);
    return 0;
}
