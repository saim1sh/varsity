#include <stdio.h>
#include<string.h>

int main() {
    char str1[100], str2[100], i, j;
    printf("Enter the first string: ");
    fgets(str1, 100, stdin);
    printf("Enter the second string: ");
    fgets(str2, 100, stdin);
    i = 0;
    while (str1[i] != '\0') {
        i++;
    }
    if (i + strlen(str2) + 1 >= sizeof(str1)) {
        printf("Error: Insufficient space in first string for concatenation.\n");
        return 1;
    }
    j = 0;
    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';
    printf("The concatenated string is: %s\n", str1);
    return 0;
}