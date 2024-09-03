#include <stdio.h>
#include <string.h>
int main() {
    char number_str[6];
    int original_number, reversed_number = 0, remainder, i;
    printf("Enter a five-digit number: ");
    scanf("%s", number_str);
    if (strlen(number_str) != 5) {
        printf("Error! Please enter a five-digit number.\n");
        return 1;
    }
    sscanf(number_str, "%d", &original_number);
    for (i = original_number; i != 0; i /= 10) {
        remainder = i % 10;
        reversed_number = reversed_number * 10 + remainder;
    }
    if (original_number == reversed_number) {
        printf("The original number %d and its reversed number %d are equal.\n", original_number, reversed_number);
    } else {
        printf("The original number %d and its reversed number %d are not equal.\n", original_number, reversed_number);
    }

    return 0;
}