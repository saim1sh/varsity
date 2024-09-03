#include <stdio.h>
#include <string.h>
int compare_strings(char *str1, char *str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            return *str1 - *str2;
        }
        str1++;
        str2++;
    }
    if (*str1 == '\0' && *str2 != '\0') {
        return -1; 
    } else if (*str1 != '\0' && *str2 == '\0') {
        return 1;
    } else {
        return 0;
    }
}
int main() {
    char str1[100], str2[100];
    int comparison_result;
    printf("Enter the first string: ");
    fgets(str1, 100, stdin);
    str1[strcspn(str1, "\n")] = '\0';
    printf("Enter the second string: ");
    fgets(str2, 100, stdin);
    str2[strcspn(str2, "\n")] = '\0';
    comparison_result = compare_strings(str1, str2);
    if (comparison_result == 0) {
        printf("Strings are equal.\n");
    } else if (comparison_result < 0) {
        printf("First string is lexicographically smaller.\n");
    } else {
        printf("First string is lexicographically bigger.\n");
    }
    return 0;
}