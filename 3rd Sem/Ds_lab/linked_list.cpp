#include <iostream>
using namespace std;

struct Node
{
   int num;
   Node *next;
};

Node *create();
bool search(Node *head, int key);
void release(Node *head);
void display(Node *head);

int main()
{
   Node *head = nullptr;
   int key;

   cout << "Enter data into the list\n";
   head = create();

   cout << "Displaying the nodes in the list:\n";
   display(head);

   cout << "Enter key to search in the list: ";
   cin >> key;

   if (search(head, key))
   {
      cout << key << " found in the list.\n";
   }
   else
   {
      cout << key << " not found in the list.\n";
   }

   release(head);
   return 0;
}

Node *create()
{
   int value;
   int n;
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

bool search(Node *head, int key)
{
   while (head != nullptr)
   {
      if (head->num == key)
      {
         return true;
      }
      head = head->next;
   }
   return false;
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