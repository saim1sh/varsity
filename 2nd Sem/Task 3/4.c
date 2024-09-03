#include <stdio.h>
int main()
{
    const float bs = 1500.00;
    const float becs = 200.00;
    const float ct = .02;
    float computerPrice, monthlySales;
    printf("Enter the price of each computer: ");
    scanf("%f", &computerPrice);
    printf("Enter the number of computers sold during the month: ");
    scanf("%f", &monthlySales);
    float bonus = becs * monthlySales;
    float commission = ct * (computerPrice * monthlySales);
    float grossSalary = bs + bonus + commission;
    printf("Gross salary for the salesperson: %.2f\n", grossSalary);
    return 0;
}