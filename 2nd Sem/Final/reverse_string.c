#include <stdio.h>
#include <string.h>

int main() {
    char str[100], new_str[100];
    // fgets(str,100,stdin);
    gets(str);
    int len = strlen(str);
    int i;
    for( i=0; i<len; i++){
        new_str[i] = str[len-i-1];
    }
    new_str[i]='\0';
    puts(new_str);
    
    return 0;
}