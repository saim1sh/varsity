#include <iostream>
using namespace std;

struct Node
{
   int data;
   Node *left;
   Node *right;
};

Node *createNode(int value)
{
   Node *newNode = new Node();
   newNode->data = value;
   newNode->left = nullptr;
   newNode->right = nullptr;
   return newNode;
}

Node *insert(Node *root, int value)
{
   if (root == nullptr)
   {
      return createNode(value);
   }
   if (value < root->data)
   {
      root->left = insert(root->left, value);
   }
   else
   {
      root->right = insert(root->right, value);
   }
   return root;
}

void preorder(Node *root)
{
   if (root != nullptr)
   {
      cout << root->data << " ";
      preorder(root->left);
      preorder(root->right);
   }
}

void inorder(Node *root)
{
   if (root != nullptr)
   {
      inorder(root->left);
      cout << root->data << " ";
      inorder(root->right);
   }
}

void postorder(Node *root)
{
   if (root != nullptr)
   {
      postorder(root->left);
      postorder(root->right);
      cout << root->data << " ";
   }
}

void release(Node *root)
{
   if (root != nullptr)
   {
      release(root->left);
      release(root->right);
      delete root;
   }
}

int main()
{
   Node *root = nullptr;
   int n, value;

   cout << "Enter the number of nodes to insert: ";
   cin >> n;

   for (int i = 0; i < n; i++)
   {
      cout << "Enter value to insert: ";
      cin >> value;
      root = insert(root, value);
   }

   cout << "Preorder Traversal: ";
   preorder(root);
   cout << endl;

   cout << "Inorder Traversal: ";
   inorder(root);
   cout << endl;

   cout << "Postorder Traversal: ";
   postorder(root);
   cout << endl;

   release(root);
   return 0;
}
