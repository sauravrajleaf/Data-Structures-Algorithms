//4 cases - 
//Removing head/first element of a Doubly linked list
//Removing tail/last element of a Doubly linked list
//Removing Kth element of a Doubly linked list
//Removing a given Node from a Doubly linked list

// CASE 4 - Deleting a node(except head node) from a Doubly linked list

// Time Complexity - O(Position of Node)

// CASE 4 - Deleting a node (except the head node) from a Doubly linked list

// Time Complexity - O(Position of Node)

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

// Function to delete a node (except the head node) from a doubly linked list
void deleteNode(Node* head) {
  // Temporary pointer to the node to be deleted
  Node* temp = head;

  // Save the previous and next nodes of the node to be deleted
  Node* prevElNode = temp->prev;
  Node* nextElNode = temp->next;

  // Check if the node to be deleted is the last node
  if (nextElNode == nullptr) {
    // Update the next pointer of the previous node to nullptr
    prevElNode->next = nullptr;

    // Update the prev pointer of the node to be deleted to nullptr
    temp->prev = nullptr;

    // Delete the node to be deleted to free up memory
    delete temp;

    return;
  }

  // Update the next pointer of the previous node to skip the node to be deleted
  prevElNode->next = nextElNode;

  // Update the prev pointer of the next node to skip the node to be deleted
  nextElNode->prev = prevElNode;

  // Update the prev and next pointers of the node to be deleted to nullptr
  temp->prev = nullptr;
  temp->next = nullptr;

  // Delete the node to be deleted to free up memory
  delete temp;

  return;
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
  vector<int> arr = {100, 12, 141, 452, 21};

  // Convert the array to a doubly linked list
  Node* head = convertArr2DLL(arr);

  cout << "Linked List before removing Kth Node " << endl;
  print(head);

  cout << endl;

  // Remove the Kth Node (in this case, removing the third node)
  deleteNode(head->next->next->next);

  cout << "Linked List after removing Kth Node" << endl;
  print(head);

  return 0;
}




//OUTPUT
//head->next
// Linked List before removing Kth Node 5
// 100 12 141 452 21 
// Linked List after removing Kth Node
// 100 141 452 21 

// head->next->next
// Linked List before removing Kth Node 
// 100 12 141 452 21 
// Linked List after removing Kth Node
// 100 12 452 21 