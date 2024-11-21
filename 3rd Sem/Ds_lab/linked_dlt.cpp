#include <iostream>
using namespace std;

struct Node
{
   int num;
   Node *next;
};

Node *create();
Node *deleteNode(Node *head, int value);
void release(Node *head);
void display(Node *head);

int main()
{
   Node *head = nullptr;

   cout << "Enter data into the list\n";
   head = create();

   cout << "Displaying the nodes in the list:\n";
   display(head);

   int valueToDelete;
   cout << "Enter the value to delete: ";
   cin >> valueToDelete;

   head = deleteNode(head, valueToDelete);
   cout << "Displaying the nodes after deletion:\n";
   display(head);

   release(head);
   return 0;
}

Node *deleteNode(Node *head, int value)
{
   if (head == nullptr)
   {
      return nullptr;
   }

   if (head->num == value)
   {
      Node *temp = head;
      head = head->next;
      delete temp;
      return head;
   }

   Node *current = head;
   while (current->next != nullptr && current->next->num != value)
   {
      current = current->next;
   }

   if (current->next != nullptr)
   {
      Node *temp = current->next;
      current->next = current->next->next;
      delete temp;
   }

   return head;
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