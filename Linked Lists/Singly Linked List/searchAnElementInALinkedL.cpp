// Time Complexity - 
// Best - O(1) -> If the element is found at the first index
// Average - O(N/2) -> If the element is found at somewhere in the middle
// Worst - O(N) -> Traversing the whole linked list

#include <bits/stdc++.h>
using namespace std;

// Node class for a linked list
class Node {
public:
  int data;
  Node* next;

  // Constructor with both data and next pointer
  Node(int data1, Node* next1) : data(data1), next(next1) {}

  // Constructor with only data (default next pointer is nullptr)
  Node(int data1) : data(data1), next(nullptr) {}
};

// Function to convert an array to a linked list
Node* convertArr2LL(vector<int> &arr) {
  // Initialize the head of the linked list with the first element of the array
  Node* head = new Node(arr[0]);

  // Initialize a pointer to move through the linked list
  Node* mover = head;

  // Iterate through the array starting from the second element
  for (int i = 1; i < arr.size(); i++) {
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

// Function to check if a value is present in the linked list
int checkIfPresent(Node* head, int val) {
  Node* temp = head;

  // Traverse the linked list to check if the value is present
  while (temp) {
    if (temp->data == val) {
      return 1; // Value found
    } else {
      temp = temp->next;
    }
  }

  return 0; // Value not found
}

int main() {
  // Example array
  vector<int> arr = {1, 5, 6, 3};

  // Convert the array to a linked list
  Node* head = convertArr2LL(arr);

  // Check if 0 is present in the linked list
  int val = 0;
  cout << "Is " << val << " present? " << checkIfPresent(head, val) << endl;

  // Check if 5 is present in the linked list
  val = 5;
  cout << "Is " << val << " present? " << checkIfPresent(head, val) << endl;

  return 0;
}

// OUTPUT
// Is 0 present? 0
// Is 5 present? 1
