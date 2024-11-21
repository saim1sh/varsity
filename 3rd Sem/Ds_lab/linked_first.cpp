#include <iostream>
using namespace std;

struct Node
{
   int num;
   Node *next;
};

Node *create();
Node *addNode(Node *head);
void release(Node *head);
void display(Node *head);

int main()
{
   Node *head = nullptr;

   cout << "Enter data into the list\n";
   head = create();

   cout << "Displaying the nodes in the list:\n";
   display(head);

   head = addNode(head);
   cout << "Displaying the nodes after adding a new node:\n";
   display(head);

   release(head);
   return 0;
}

Node *addNode(Node *head)
{
   Node *temp;
   int value;
   cout << "Enter number: ";
   cin >> value;

   temp = new Node();
   temp->num = value;
   temp->next = head;
   return temp;
}

Node *create()
{
   int value, n;
   Node *head = nullptr;
   Node *temp;
   Node *rear = nullptr;

   do
   {
      cout << "Enter number: ";
      cin >> value;

      temp = new Node();
      temp->num = value;
      temp->next = nullptr;

      if (head == nullptr)
      {
         head = temp;
      }
      else
      {
         rear->next = temp;
      }

      rear = temp;

      cout << "Do you wish to continue [1/0]: ";
      cin >> n;

   } while (n != 0);

   cout << "\n";
   return head;
}

void display(Node *head)
{
   while (head != nullptr)
   {
      cout << head->num << "\t";
      head = head->next;
   }
   cout << "\n";
}

void release(Node *head)
{
   Node *temp;
   while (head != nullptr)
   {
      temp = head;
      head = head->next;
      delete temp;
   }
}