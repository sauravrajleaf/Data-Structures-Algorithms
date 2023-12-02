//4 cases - 
//Inserting head/first element of a linked list
//Inserting tail/last element of a linked list
//Inserting Kth element of a linked list
//Inserting a given value from a linked list

// CASE 1 - Inserting head/first element of a linked list

// Time Complexity - O(1)


#include <bits/stdc++.h>

using namespace std;

class Node {
  public:

  // Member variables
  int data;
  Node* next;

  // Constructor function
  Node(int data1, Node* next1) {
    data = data1;
    next = next1;
  } 

  // Constructor function
  Node(int data1) {
    data = data1;
    next = nullptr;
  }

};

// Function to insert a new node at the head of the linked list
Node* insertHead(Node* head, int value) {
  // One-liner: Create a new node with the given value and next pointing to the current head
  return new Node(value, head);
}

// Function to print the elements of a linked list
void print(Node* head) {
  Node* temp = head;

  while(temp) {
    cout << temp->data << " ";
    temp = temp->next;
  }
}

// Function to convert an array to a linked list
Node* convertArr2LL(vector<int>& arr) {
  // Initialize the head of the linked list with the first element of the array
  Node* head = new Node(arr[0]);

  // Initialize a pointer to move through the linked list
  Node* mover = head;

  // Iterate through the array starting from the second element
  for(int i=1; i<arr.size(); i++) {
    // Create a new node with the current array element
    Node* temp = new Node(arr[i]);

    // Update the next pointer of the current node to point to the new node
    mover->next = temp;

    // Move the pointer to the newly added node
    mover = temp;
  }

  // Return the head of the linked list
  return head;
}

int main() {
  // Example array
  vector<int> arr = {12, 134, 142, 3, 1};

  // Convert the array to a linked list
  Node* head = convertArr2LL(arr);

  cout << "Linked List before inserting new head" << endl;
  print(head);

  cout << endl;

  // Value to insert at the head
  int value = 9;

  // Insert a new node at the head of the linked list
  head = insertHead(head, value);

  cout << "Linked List after inserting new head" << endl;
  print(head);

  return 0;
}

// OUTPUT
//new  Head value - 201
// Linked List before inserting new head
// 12 134 142 3 1 
// Linked List after inserting new head
// 201 12 134 142 3 1 


//new Head value - 99
// Linked List before inserting new head
// 12 134 142 3 1 
// Linked List after inserting new head
// 99 12 134 142 3 1 