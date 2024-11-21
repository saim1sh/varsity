#include <stdio.h>
#include <string.h>

int main() {
    FILE* ptr;
    FILE* ptr1;

    ptr = fopen("file.txt", "w");
    if (ptr == NULL) {
        return 1;
    }

    fprintf(ptr, "%s\n", "Alice");
    fprintf(ptr, "%s\n", "Bob");
    fprintf(ptr, "%s\n", "Charlie");
    fprintf(ptr, "%s\n", "Dave");
    fclose(ptr);

    ptr = fopen("file.txt", "r");
    if (ptr == NULL) {
        return 1;
    }

    char name[10];
    ptr1 = fopen("output.txt", "w+");
    if (ptr1 == NULL) {
        fclose(ptr);
        return 1;
    }

    fscanf(ptr, "%s", name);
    printf("%s\n", name);
    if (strcmp(name, "Alice") == 0) {
        fprintf(ptr1, "ALICE\n");
    }
    fscanf(ptr, "%s", name);
    printf("%s\n", name);
    if (strcmp(name, "Bob") == 0) {
        fprintf(ptr1, "BOB\n");
    }
    fscanf(ptr, "%s", name);
    printf("%s\n", name);
    if (strcmp(name, "Charlie") == 0) {
        fprintf(ptr1, "CHARLIE\n");
    }
    fscanf(ptr, "%s", name);
    printf("%s\n", name);
    if (strcmp(name, "Dave") == 0) {
        fprintf(ptr1, "DAVE\n");
    }

    fclose(ptr);
    fclose(ptr1);

    ptr1 = fopen("output.txt", "r");
    if (ptr1 == NULL) {
        return 1;
    }

    char outputName[20];
    fscanf(ptr1, "%s", outputName);
    printf("%s\n", outputName);
    fscanf(ptr1, "%s", outputName);
    printf("%s\n", outputName);
    fscanf(ptr1, "%s", outputName);
    printf("%s\n", outputName);
    fscanf(ptr1, "%s", outputName);
    printf("%s\n", outputName);

    fclose(ptr1);

    return 0;
}