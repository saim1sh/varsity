#include <stdio.h>

int main() {
    char str[100];
    int i;
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    printf("The individual characters are: \n");
    for (i = 0; str[i] != '\0'; i++) {
        printf("%c \n", str[i]);
    }
    printf("\n");
    return 0;
}