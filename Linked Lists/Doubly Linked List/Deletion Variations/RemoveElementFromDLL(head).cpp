//4 cases - 
//Removing head/first element of a linked list
//Removing tail/last element of a linked list
//Removing Kth element of a linked list
//Removing a given value from a linked list

// CASE 1 - Removing head/first element of a linked list

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

// Function to remove the head of a doubly linked list
Node* removesHead(Node* head) {
  // Edge case: if the linked list is empty or has only one element
  if (head == nullptr || head->next == nullptr) {
    return nullptr;
  }

  // Save the current head node
  Node* prev = head;

  // Update the head to the next node
  head = head->next;

  // Update the prev pointer of the new head to nullptr
  head->prev = nullptr;

  // Update the next pointer of the previous head to nullptr
  prev->next = nullptr;

  // Delete the previous head to free up memory
  delete prev;

  // Return the new head of the linked list
  return head;
}



// Function to print the elements of the doubly linked list
void print(Node* head) {
  Node* temp = head;

  while(temp) {
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
  vector<int> arr = {100, 12, 141, 452, 21};

  // Convert the array to a doubly linked list
  Node* head = convertArr2DLL(arr);

  cout << "Linked List before removing head/first element" << endl;
  print(head);

  cout << endl;

  // Remove the head of the linked list
  head = removesHead(head);

  cout << "Linked List after removing head/first element" << endl;
  print(head);

  return 0;
}

// OUTPUT
// Linked List before removing head/first element
// 12 141 452 21 
// Linked List after removing head/first element
// 141 452 21 

// Linked List before removing head/first element
// 100 12 141 452 21 
// Linked List after removing head/first element
// 12 141 452 21 