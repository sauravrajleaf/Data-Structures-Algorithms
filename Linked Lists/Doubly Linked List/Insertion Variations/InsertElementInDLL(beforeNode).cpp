//4 cases - 
//Inserting head/first element of a Doubly linked list
//Inserting before tail/last element of a Doubly linked list
//Inserting before Kth element of a Doubly linked list
//Inserting before a given node of a Doubly linked list

// CASE 4 - Inserting a node (except the head node) from a Doubly linked list. The node will be given

// Time Complexity - O(1)

#include<bits/stdc++.h>

using namespace std;

class Node {
public:
  int data;
  Node* next;
  Node* prev;

  // Constructor with both data, next, and prev pointers
public:
  Node(int data1, Node* next1, Node* prev1) : data(data1), next(next1), prev(prev1) {}

  // Constructor with only data (default next and prev pointers are nullptr)
public:
  Node(int data1) : data(data1), next(nullptr), prev(nullptr) {}
};

// Function to insert a new node before a given node in a doubly linked list
void insertBeforeNode(Node* givenNode, int value) {
  // Create a new node with the given value, next pointing to the given node, and prev pointing to the previous node
  Node* newNode = new Node(value, givenNode, givenNode->prev);

  // Update the next pointer of the previous node to point to the new node
  givenNode->prev->next = newNode;

  // Update the prev pointer of the given node to point to the new node
  givenNode->prev = newNode;
}

// Function to print the elements of the doubly linked list
void print(Node* head) {
  Node* temp = head;

  while (temp) {
    cout << temp->data << " ";
    temp = temp->next;
  }
}

// Function to convert an array to a doubly linked list
Node* convertArr2DLL(vector<int> &arr) {
  // Initialize the head of the doubly linked list with the first element of the array
  Node* head = new Node(arr[0]);

  // Initialize a pointer to keep track of the previous node
  Node* prev = head;

  // Iterate through the array starting from the second element
  for (int i = 1; i < arr.size(); i++) {
    // Create a new node with the current array element, nullptr for next, and the previous node as prev
    Node* temp = new Node(arr[i], nullptr, prev);

    // Update the next pointer of the previous node to point to the new node
    prev->next = temp;

    // Move the previous pointer to the newly added node
    prev = temp;
  }

  // Return the head of the doubly linked list
  return head;
}

int main() {
  // Example array
  vector<int> arr = {12, 141, 452, 21};

  // Convert the array to a doubly linked list
  Node* head = convertArr2DLL(arr);
  int value = 120;

  cout << "Linked List before inserting before node " << value << endl;
  print(head);

  cout << endl;

  // Insert a new node with the given value before the kth position
  insertBeforeNode(head->next->next->next, value);

  cout << "Linked List after inserting before node" << endl;
  print(head);

  return 0;
}

// OUTPUT
// Linked List before kth position 120
// 12 141 452 21 
// Linked List after kth position
// 12 120 141 452 21 

// Linked List before kth position 120
// 12 141 452 21 
// Linked List after kth position
// 12 141 452 120 21 