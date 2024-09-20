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
      if (string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u' || string[i] == 'A' || string[i] == 'E' || string[i] == 'I' || string[i] == 'O' || string[i] == 'U')
      {
         vowel_cnt++;
      }
      i++;
   }
   printf("Number of vowels in the string: %d\n", vowel_cnt);
   int str_size = 0;
   while (string[str_size] != '\0')
   {
      str_size++;
      i++;
   }
   char reversed_string[50];
   for (int i = 0; i < str_size; i++)
   {
      reversed_string[i] = string[str_size - 1 - i];
   }
   reversed_string[str_size] = '\0';
   printf("Reversed string: %s\n", reversed_string);
}