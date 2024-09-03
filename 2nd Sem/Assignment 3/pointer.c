#include<stdio.h>
int main(){
   char c ='Q';
   char *char_pointer = &c;
   printf("%c %c\n",c,*char_pointer);
   c ='z';
   printf("%c %c\n",c,*char_pointer);
   *char_pointer= 'Y';
   printf("%c %c\n",c,*char_pointer);
}