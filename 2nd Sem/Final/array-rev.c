#include <stdio.h>
// #include <string.h>

int main() {
    int str[5], new_str[5];
   for (int i = 0; i < 5; i++)
   {
      scanf("%d",&str[i]);
   }
    int i;
    for( i=0; i<5; i++){
        new_str[i] = str[5-i-1];
    }
    for (int i = 0; i < 5; i++)
   {
      printf("%d ",new_str[i]);
   }
    return 0;
}