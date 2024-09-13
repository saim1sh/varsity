#include <stdio.h>
int main()
{
   int arr[5] = {1, 2, 3, 4};
   int elem, pos;
   printf("Enter element and position: ");
   scanf("%d %d", &elem, &pos);
   for (int i = 5; i > pos; i--)
   {
      arr[i] = arr[i - 1];
   }
   arr[pos] = elem;
   for (int i = 0; i < 5; i++)
   {
      printf("%d ", arr[i]);
   }
}