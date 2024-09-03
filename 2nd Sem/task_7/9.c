#include <stdio.h>
#include <string.h>

int main() {
    char source[100], destination[100];
    int i = 0;
    printf("Enter the source string: ");
    fgets(source, 100, stdin);
    source[strcspn(source, "\n")] = '\0';
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
    printf("The copied string is: %s\n", destination);
    return 0;
}