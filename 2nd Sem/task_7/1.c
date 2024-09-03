#include <stdio.h>

int main() {
    char str[100];
    int i, length = 0;
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    for (i = 0; str[i] != '\0'; i++) {
        length++;
    }
    length--;
    printf("The length of the string is: %d\n", length);
    return 0;
}