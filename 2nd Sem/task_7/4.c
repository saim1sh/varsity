#include <stdio.h>

int main() {
    char str[100];
    int i, word_count = 0;
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    if (str[0] == '\n') {
        word_count = 0;
    } else {
        for (i = 0; str[i] != '\0'; i++) {
            if ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t') && str[i + 1] != ' ') {
                word_count++;
            }
        }
        if (str[i - 1] != ' ' && str[i - 1] != '\n' && str[i - 1] != '\t') {
            word_count++;
        }
    }
    printf("Total number of words in the string: %d\n", word_count);
    return 0;
}