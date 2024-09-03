#include <stdio.h>
#include <ctype.h>

int main() {
    char str[100];
    int i;
    printf("Enter a sentence: ");
    fgets(str, 100, stdin);
    for (i = 0; str[i] != '\0'; i++) {
        if (islower(str[i])) {
            str[i] = toupper(str[i]);
        } else if (isupper(str[i])) {
            str[i] = tolower(str[i]);
        }
    }
    printf("The sentence after replacing case: %s\n", str);
    return 0;
}