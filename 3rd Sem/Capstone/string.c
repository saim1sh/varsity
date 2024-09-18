#include <stdio.h>
#include <string.h>
int main()
{
   char string[50];
   scanf("%s", &string);
   int vowel_cnt = 0;
   int i = 0;
   while (string[i] != '\0')
   {
      if (string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u')
      {
         vowel_cnt++;
      }
      i++;
   }
   printf("Number of vowels in the string: %d\n", vowel_cnt);
}