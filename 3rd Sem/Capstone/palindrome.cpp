#include<bits/stdc++.h>
using namespace std;
void is_pal(char st[]){
    int len = 0;
    int i = 0;
    while (st[i] != '\0') {
        len++;
        i++;
    }
    char reversed[10];
    for (int i = len - 1; i >= 0; i--) {
        reversed[len - 1 - i] = st[i];
    }
    reversed[len] = '\0';
    bool boom=strcmp(st,reversed);
    if(!boom){
        cout << reversed << " is Palindrome" << "\n";
    }
    else{
        cout << reversed << " is not Palindrome" << "\n";
    }
}
int main() {
    char str[10];
    cin >> str;
    is_pal(str);
    return 0;
}
