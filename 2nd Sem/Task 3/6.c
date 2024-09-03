#include <stdio.h>
int main()
{
    float total_sell_price, total_prof;
    printf("Enter the total selling price of 15 items : ");
    scanf("%f\n", &total_sell_price);
    printf("Enter the total profit earned on the items : ");
    scanf("%f\n", &total_prof);
    float per_item_price = (total_sell_price - total_prof) / 15;
    printf("Cost price of one item is : %.2f\n", per_item_price);
    return 0;
}