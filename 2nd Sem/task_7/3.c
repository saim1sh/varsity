#include <stdio.h>

int main() {
    char str[100];
    int i, length;

    printf("Enter a string: ");
    fgets(str, 100, stdin);
    length = 0;
    for (i = 0; str[i] != '\0'; i++) {
        length++;
    }
    length--;
    printf("The characters of the string in reverse are: \n");
    for (i = length - 1; i >= 0; i--) {
        printf("%c \n", str[i]);
    }
    printf("\n");
    return 0;
}