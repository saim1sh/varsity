#include <stdio.h>
int main()
{
    float distance;
    printf("Enter Distance : ");
    scanf("%f", &distance);
    printf("Distance in feet : %.2f\n", distance / 3.21);
    printf("Distance in inches : %.2f\n", distance / 39.37);
    printf("Distance in centimeters : %.2f\n", distance / 100);
}
