//4 cases - 
//Inserting head/first element of a linked list
//Inserting tail/last element of a linked list
//Inserting Kth element of a linked list
//Inserting a given value from a linked list

// CASE 2 - Inserting tail/last element of a linked list

// Time Complexity - O(N), N is the size of the linked list


#include <bits/stdc++.h>

using namespace std;

class Node {
  public:
  // Member variables
  int data;
  Node* next;

  // Constructor function
  public:
  Node(int data1, Node* next1) {
    data = data1;
    next = next1;
  }

  // Constructor function
  public:
  Node(int data1) {
    data = data1;
    next = nullptr;
  }

};

// Function to insert a new node at the tail of the linked list
Node* insertTail(Node* head, int value) {
  // Initialize a pointer to traverse the linked list
  Node* temp = head;

  // Traverse the linked list until the last node
  while(temp->next != NULL) {
    temp = temp->next;
  }

  // Create a new node with the given value and add it to the end of the linked list
  temp->next = new Node(value);

  // Return the head of the linked list
  return head;
}

// Function to print the elements of a linked list
void print(Node* head) {
  Node* temp = head;

  // Traverse the linked list and print each element
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
  vector<int> arr = {45, 23, 12, 34, 2};

  // Convert the array to a linked list
  Node* head = convertArr2LL(arr);

  cout << "Linked List before inserting new tail" << endl;
  print(head);

  cout << endl;

  // Value to insert at the tail
  int value = 90;

  // Insert a new node at the tail of the linked list
  head = insertTail(head, value);

  cout << "Linked List after inserting new tail" << endl;
  print(head);

  return 0;
}


// OUTPUT
// new tail value = 9
// Linked List before inserting new tail
// 45 45 23 12 34 2 
// Linked List after inserting new tail
// 45 45 23 12 34 2 9 

// new tail value = 90
// Linked List before inserting new tail
// 45 23 12 34 2 
// Linked List after inserting new tail
// 45 23 12 34 2 90 