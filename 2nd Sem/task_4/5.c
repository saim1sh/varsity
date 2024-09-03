#include <stdio.h>

int main() {
    int arif_age, fahmid_age, joy_age;
    printf("Enter Arif's age: ");
    scanf("%d", &arif_age);
    printf("Enter Fahmid's age: ");
    scanf("%d", &fahmid_age);
    printf("Enter Joy's age: ");
    scanf("%d", &joy_age);
    int youngest_age = arif_age;
    char *youngest_name = "Arif";
    if (fahmid_age < youngest_age) {
        youngest_age = fahmid_age;
        youngest_name = "Fahmid";
    }
    if (joy_age < youngest_age) {
        youngest_age = joy_age;
        youngest_name = "Joy";
    }
    printf("%s is the youngest with age %d.\n", youngest_name, youngest_age);

    return 0;
}