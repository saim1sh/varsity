#include <stdio.h>
int main() {
    float angle1, angle2, angle3;
    printf("Enter the first angle of the triangle: ");
    scanf("%f", &angle1);
    printf("Enter the second angle of the triangle: ");
    scanf("%f", &angle2);
    printf("Enter the third angle of the triangle: ");
    scanf("%f", &angle3);
    if (angle1 + angle2 + angle3 == 180) {
        printf("The triangle is valid.\n");
    } else {
        printf("The triangle is not valid.\n");
    }

    return 0;
}