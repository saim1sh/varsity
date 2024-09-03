#include <stdio.h>

int main() {
    char str[100];
    int i, alphabets = 0, digits = 0, special_chars = 0;
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    for (i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            alphabets++;
        } else if (str[i] >= '0' && str[i] <= '9') {
            digits++;
        } else {
            special_chars++;
        }
    }
    printf("Number of alphabets: %d\n", alphabets);
    printf("Number of digits: %d\n", digits);
    printf("Number of special characters: %d\n", special_chars);
    return 0;
}