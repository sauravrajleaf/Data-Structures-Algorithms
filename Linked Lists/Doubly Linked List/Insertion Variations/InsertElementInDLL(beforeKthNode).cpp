//4 cases - 
//Inserting head/first element of a Doubly linked list
//Inserting before tail/last element of a Doubly linked list
//Inserting before Kth element of a Doubly linked list
//Inserting before a given node of a Doubly linked list

// CASE 3 - Inserting before Kth position of a Doubly linked list

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

// Function to insert a new node before the kth element in a doubly linked list
Node* insertBeforeKthElement(Node* head, int k, int value) {
  // Initialize a temporary pointer to traverse the linked list
  Node* temp = head;

  // Initialize a counter to keep track of the current position in the linked list
  int cnt = 0;

  // Traverse the linked list to find the kth element
  while (temp != nullptr) {
    cnt++;
    if (cnt == k) {
      // Break out of the loop when the kth element is found
      break;
    }
    temp = temp->next;
  }

  // If k is larger than the size of the linked list, do nothing
  if (temp == nullptr) {
    return head;
  }

  // Retrieve the previous node before the kth element
  Node* prev = temp->prev;

  // Create a new node with the given value, pointing to the kth element as next and the previous node as prev
  Node* newNode = new Node(value, temp, prev);

  // Update the next pointer of the previous node to point to the new node
  prev->next = newNode;

  // Update the previous pointer of the kth element to point to the new node
  temp->prev = newNode;

  // Return the head of the updated doubly linked list
  return head;
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

  // Specify the value and position where the new node should be inserted
  int value = 10; 
  int k = 2;

  cout << "Linked List before inserting at position " << k << endl;
  print(head);
  cout << endl;

  // Insert a new node before the kth element
  head = insertBeforeKthElement(head, k, value);

  cout << "Linked List after inserting at position " << k << endl;
  print(head);

  return 0;
}

// OUTPUT
// Linked List before kth position 1
// 12 141 452 21 
// Linked List after kth position
// 10 12 141 452 21 

// Linked List before kth position 4
// 12 141 452 21 
// Linked List after kth position
// 12 141 452 10 21 

// Linked List before kth position 2
// 12 141 452 21 
// Linked List after kth position
// 12 10 141 452 21 