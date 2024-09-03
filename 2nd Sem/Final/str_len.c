#include<stdio.h>
#include<string.h>

int main(){
   char str[20];
   gets(str);
   int count=0,i=0;
   while(str[i]!='\0'){
      count++;
      i++;
   }
   printf("%d",count);
}