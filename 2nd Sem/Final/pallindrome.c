#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int palindrome = 1;
    gets(str);
    int len = strlen(str);
    
    for(int i=0; i<len/2; i++){
        if(str[i] != str[len-i-1]){
            palindrome = 0;
            break;
        }
    }
    if(palindrome){
        printf("This is a palindrome number");
    }
    else{
        printf("This is not a palindrome number");
    }
    
    return 0;
}
