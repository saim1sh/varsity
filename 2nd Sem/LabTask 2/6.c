#include <stdio.h>
#include <math.h>
int main()
{
    int basic_sal;
    printf("Enter basic salary : ");
    scanf("%d", &basic_sal);
    int dearness = basic_sal * .4;
    int rent = basic_sal * .2;
    int gross_sal = basic_sal + dearness + rent;
    printf("Gross_sal is : %d", gross_sal);
    return 0;
}
