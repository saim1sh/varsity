//FAHEEM UDDIN -232-35-347-41(k)


#include <stdio.h>

int main() {
    int num, reversedNum = 0, originalNum;

    printf("Enter a five-digit number: ");
    scanf("%d", &num);

    originalNum = num;

    while (num != 0) {
        reversedNum = reversedNum * 10 + num % 10;
        num /= 10;
    }

    printf("Reversed Number: %d\n", reversedNum);
    printf(originalNum == reversedNum ? "The numbers are equal.\n" : "The numbers are not equal.\n");

}