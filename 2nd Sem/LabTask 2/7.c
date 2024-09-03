#include <stdio.h>
int main()
{
    int num[5];
    int aggregate_marks = 0;
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &num[i]);
        aggregate_marks += num[i];
    }
    printf("Aggregate marks : %d\n", aggregate_marks);
    float avg_marks = aggregate_marks / 5.0;
    printf("Average marks : %.1f\n", avg_marks);
    return 0;
}
