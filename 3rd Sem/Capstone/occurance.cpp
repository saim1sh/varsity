#include <bits/stdc++.h>
using namespace std;

void count_char(char str[], char ch){
   int i = 0;
   int len = 0;
   while (str[i] != '\0')
   {
      len++;
      i++;
   }
   int occurances = 0;
   for(int i = 0; i < len; i++){
      if(str[i] == ch){
         occurances++;
      }
   }
   cout << "The character '" << ch << "' occurs " << occurances << " times in the given string." << "\n";
}
int main()
{
   char str[10];
   cin >> str;
   count_char(str, 'A');

   return 0;
}