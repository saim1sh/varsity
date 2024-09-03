#include <stdio.h>
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("Add = %d\n", a + b);
    printf("Subtract = %d\n", a - b);
    printf("Multiply = %d\n", a * b);
    printf("Divide = %.2f\n", (float)a / b);
    return (0);
}
