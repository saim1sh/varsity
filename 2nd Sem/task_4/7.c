#include <stdio.h>
int main() {
    int units;
    float bill_amount = 0.0;
    printf("Enter the number of units consumed: ");
    scanf("%d", &units);
    if (units <= 200) {
        bill_amount = units * 0.50;
    } else if (units <= 400) {
        bill_amount = 100 + (units - 200) * 0.65;
    } else if (units <= 600) {
        bill_amount = 230 + (units - 400) * 0.80;
    } else {
        bill_amount = 390 + (units - 600) * 1.00;
    }
    printf("The amount to be paid by the customer is Rs. %.2f\n", bill_amount);

    return 0;
}