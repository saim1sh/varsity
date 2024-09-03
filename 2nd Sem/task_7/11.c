#include <stdio.h>
#include <ctype.h> // For tolower() function (optional)

int main() {
    char str[100], max_char;
    int i, j, char_counts[256] = {0};
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    for (i = 0; str[i] != '\0'; i++) {
        char_counts[(int)str[i]]++;
    }
    max_char = str[0];
    for (i = 1; i < 256; i++) {
        if (char_counts[i] > char_counts[(int)max_char]) {
            max_char = (char)i;
        }
    }
    printf("The maximum occurring character is: '%c' (appears %d times)\n", max_char, char_counts[(int)max_char]);
    return 0;
}