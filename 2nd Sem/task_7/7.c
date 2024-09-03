#include <stdio.h>

int main() {
    char str[100];
    int i, j;
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    int freq[256] = {0}; 
    for (i = 0; str[i] != '\0'; i++) {
        freq[str[i]]++;
    }
    printf("Frequency of characters:\n");
    for (j = 0; j < 256; j++) {
        if (freq[j] > 0) {
            printf("%c: %d\n", j, freq[j]);
        }
    }
    return 0;
}