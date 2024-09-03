#include <stdio.h>
int main() {
    float physics, chemistry, biology, mathematics, computer;
    float total_marks, percentage;
    printf("Enter marks of Physics: ");
    scanf("%f", &physics);
    printf("Enter marks of Chemistry: ");
    scanf("%f", &chemistry);
    printf("Enter marks of Biology: ");
    scanf("%f", &biology);
    printf("Enter marks of Mathematics: ");
    scanf("%f", &mathematics);
    printf("Enter marks of Computer: ");
    scanf("%f", &computer);
    total_marks = physics + chemistry + biology + mathematics + computer;
    percentage = (total_marks / 500) * 100;
    char grade;
    if (percentage >= 90) {
        grade = 'A';
    } else if (percentage >= 80) {
        grade = 'B';
    } else if (percentage >= 70) {
        grade = 'C';
    } else if (percentage >= 60) {
        grade = 'D';
    } else if (percentage >= 40) {
        grade = 'E';
    } else {
        grade = 'F';
    }
    printf("Percentage: %.2f%%\n", percentage);
    printf("Grade: %c\n", grade);

    return 0;
}