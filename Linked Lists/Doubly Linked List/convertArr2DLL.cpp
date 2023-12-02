// Time Complexity - 
// Best - O(N) -> If the element is found at the first index
// Average - O(N) -> If the element is found at somewhere in the middle
// Worst - O(N) -> Traversing the whole linked list

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

  cout << "Doubly Linked List after conversion" << endl;
  print(head);

  return 0;
}


//OUTPUT
// vector<int> arr = {12,141,452,21};
// Doubly Linked List after conversion
// 12 141 452 21 