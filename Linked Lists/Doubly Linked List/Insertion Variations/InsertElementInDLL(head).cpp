//4 cases - 
//Inserting head/first element of a Doubly linked list
//Inserting tail/last element of a Doubly linked list
//Inserting before Kth element of a Doubly linked list
//Inserting before a given node of a Doubly linked list

// CASE 1 - Inserting new head/first element of a Doubly linked list

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

// Function to insert a new node as the new head of a doubly linked list
Node* insertNewHead(Node* head, int value) {
  // Create a new node with the given value, pointing to the current head as next and nullptr as prev
  Node* newHead = new Node(value, head, nullptr);

  // Update the previous pointer of the current head to point to the new head
  head->prev = newHead;

  // Return the new head of the doubly linked list
  return newHead;
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
  vector<int> arr = {12, 141, 452, 21};

  // Convert the array to a doubly linked list
  Node* head = convertArr2DLL(arr);

  int newHead = 10; 

  cout << "Linked List before inserting new head "<< newHead << endl;
  print(head);

  cout << endl;


  // Remove the head of the linked list
  head = insertNewHead(head, newHead);

  cout << "Linked List after inserting new head" << endl;
  print(head);

  return 0;
}

//OUTPUT
// Linked List before inserting new head 10
// 12 141 452 21 
// Linked List after inserting new head
// 10 12 141 452 21 