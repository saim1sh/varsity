#include <iostream>

using namespace std;

// Define a struct to represent a node in the linked list
struct Node {
    int data;       // Data part of the node
    Node* next;     // Pointer to the next node
};

// Global pointer to the head of the linked list
Node* head = nullptr;

// Function to insert a new node at the beginning of the list
void insertAtFirst(int x) {
    Node* newNode = new Node(); // Create a new node
    newNode->data = x;          // Assign data to the new node
    newNode->next = head;       // Point new node to the current head
    head = newNode;             // Update head to point to the new node
}

// Function to insert a new node at the end of the list
void insertAtLast(int x) {
    Node* newNode = new Node(); // Create a new node
    newNode->data = x;          // Assign data to the new node
    newNode->next = nullptr;    // New node will be the last node

    // If the list is empty, make the new node the head
    if (head == nullptr) {
        head = newNode;
        return;
    }

    // Traverse to the last node
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next; // Move to the next node
    }
    temp->next = newNode; // Link the last node to the new node
}

// Function to insert a new node at a specified position
void insertAtPosition(int x, int pos) {
    Node* newNode = new Node(); // Create a new node
    newNode->data = x;          // Assign data to the new node

    // If inserting at the head (position 1)
    if (pos == 1) {
        newNode->next = head;   // Link new node to current head
        head = newNode;         // Update head to point to the new node
        return;
    }

    // Traverse the list to find the position to insert
    Node* temp = head;
    int count = 1;

    // Move to the node just before the desired position
    while (temp != nullptr && count < pos - 1) {
        temp = temp->next; // Move to the next node
        count++;
    }

    // If the position is out of bounds, print an error message
    if (temp == nullptr) {
        cout << "Position out of bounds." << endl;
        delete newNode; // Free memory if position is invalid
        return;
    }

    // Link the new node to the next node
    newNode->next = temp->next; // Link new node to the next node
    temp->next = newNode;       // Link previous node to the new node
}

// Function to display the linked list
void display() {
    Node* temp = head; // Start from the head
    while (temp != nullptr) {
        cout << temp->data << " -> "; // Print the data
        temp = temp->next; // Move to the next node
    }
    cout << "nullptr" << endl; // Indicate the end of the list
}

// Main function to demonstrate linked list operations
int main() {
    insertAtFirst(10); // Insert 10 at the beginning
    insertAtLast(20);  // Insert 20 at the end
    insertAtPosition(15, 2); // Insert 15 at position 2
    display(); // Display the linked list

    return 0; // Indicate that the program ended successfully
}