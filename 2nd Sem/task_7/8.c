#include <stdio.h>
#include <string.h>

int main() {
    char str[100], sub_str[100];
    int start, length;
    int actual_length;
    printf("Enter the main string: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';
    printf("Enter the starting position (index) for the substring (0-based): ");
    scanf("%d", &start);
    printf("Enter the length of the substring: ");
    scanf("%d", &length);
    if (start < 0 || start >= strlen(str)) {
        printf("Error: Invalid starting position.\n");
        return 1;
    }
    actual_length = length > strlen(str) - start ? strlen(str) - start : length;
    strncpy(sub_str, str + start, actual_length);
    sub_str[actual_length] = '\0';
    printf("The extracted substring is: %s\n", sub_str);
    return 0;
}