#include <iostream>
using namespace std;

// Define a structure to represent a node in the binary search tree
struct Node {
    int data;       // Data part of the node
    Node *left;     // Pointer to the left child
    Node *right;    // Pointer to the right child
};

// Function to create a new node with a given value
Node *createNode(int value) {
    Node *newNode = new Node(); // Allocate memory for a new node
    newNode->data = value;      // Set the node's data
    newNode->left = nullptr;    // Initialize left child as nullptr
    newNode->right = nullptr;   // Initialize right child as nullptr
    return newNode;             // Return the newly created node
}

// Function to insert a value into the binary search tree
Node *insert(Node *root, int value) {
    // If the tree is empty, create a new node and return it
    if (root == nullptr) {
        return createNode(value);
    }
    
    // Recursively insert the value in the left or right subtree
    if (value < root->data) {
        root->left = insert(root->left, value); // Insert in the left subtree
    } else {
        root->right = insert(root->right, value); // Insert in the right subtree
    }
    return root; // Return the unchanged root pointer
}

// Preorder traversal of the binary search tree
void preorder(Node *root) {
    if (root != nullptr) {
        cout << root->data; // Print the node's data
        if (root->left || root->right) {
            cout << " -> "; // Print arrow if there are children
            preorder(root->left); // Traverse the left subtree
            if (root->right) {
                cout << " -> "; // Print arrow if there is a right child
                preorder(root->right); // Traverse the right subtree
            }
        }
    }
}

// Inorder traversal of the binary search tree
void inorder(Node *root) {
    if (root != nullptr) {
        if (root->left) {
            inorder(root->left); // Traverse the left subtree
            cout << " -> "; // Print arrow after left subtree
        }
        cout << root->data; // Print the node's data
        if (root->right) {
            cout << " -> "; // Print arrow if there is a right child
            inorder(root->right); // Traverse the right subtree
        }
    }
}

// Postorder traversal of the binary search tree
void postorder(Node *root) {
    if (root != nullptr) {
        if (root->left) {
            postorder(root->left); // Traverse the left subtree
            cout << " -> "; // Print arrow after left subtree
        }
        if (root->right) {
            postorder(root->right); // Traverse the right subtree
            cout << " -> "; // Print arrow after right subtree
        }
        cout << root->data; // Print the node's data
    }
}

// Function to release the memory allocated for the binary search tree
void release(Node *root) {
    if (root != nullptr) {
        release(root->left); // Recursively release left subtree
        release(root->right); // Recursively release right subtree
        delete root; // Free the current node
    }
}

// Main function to demonstrate the binary search tree operations
int main() {
    Node *root = nullptr; // Initialize the root of the tree
    int n, value;

    // Ask the user for the number of nodes to insert
    cout << "Enter the number of nodes to insert: ";
    cin >> n;

    // Loop to insert nodes into the binary search tree
    for (int i = 0; i < n; i++) {
        cout << "Enter value to insert: ";
        cin >> value; // Read value from the user
        root = insert(root, value); // Insert the value into the tree
    }

    // Display traversals of the binary search tree
    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;

    // Release memory allocated for the binary search tree
    release(root);
    return 0; // Indicate that the program ended successfully
}