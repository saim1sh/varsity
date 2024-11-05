#include <bits/stdc++.h>
using namespace std;
#define size 4
int top = -1;

void push(int stack[], int x)
{
   if (top == size - 1)
   {
      cout << "Stack Overflow" << endl;
   }
   else
   {
      top++;
      stack[top] = x;
   }
}

void pop(int stack[])
{
   if (top == -1)
   {
      cout << "Stack Underflow" << endl;
   }
   else
   {
      cout << "Popped element is: " << stack[top] << endl;
      top--;
   }
}
void peek(int stack[])
{
   if (top == -1)
   {
      cout << "Stack is empty" << endl;
   }
   else
   {
      cout << "Top element is: " << stack[top] << endl;
   }
}
int main()
{
   int stack[size];
   peek(stack);
   push(stack, 67);
   push(stack, 23);
   push(stack, 89);
   push(stack, 12);
   push(stack, 12);
   peek(stack);
   pop(stack);
   push(stack, 12);

   return 0;
}