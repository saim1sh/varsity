#include<stdio.h>
 
int main()
{
    struct emp
   {
      char name[20];
      int id;
      char dep[30];
   };
   struct emp emp_num[5];
   int i;
   for( i=0; i<5; i++){
      scanf("%s %d %s",&emp_num[i].name,&emp_num[i].id,&emp_num[i].dep);
   }
   for( i=0; i<5; i++){
      printf("%s %d %s",emp_num[i].name,emp_num[i].id,emp_num[i].dep);
   }
}