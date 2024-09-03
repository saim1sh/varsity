//FAHEEM UDDIN -232-35-347-41(k)

#include <stdio.h>

int main() {
    float basic_salary, dearness_allowance, house_rent, gross_salary;
    printf("Enter Fahim's basic salary: ");
    scanf("%f", &basic_salary);
    dearness_allowance = 0.40 * basic_salary;
    house_rent = 0.20 * basic_salary;
    gross_salary = basic_salary + dearness_allowance + house_rent;
    printf("Fahim's gross salary is: %.2f\n", gross_salary);
   return 0;
}