//4 cases - 
//Removing head/first element of a linked list
//Removing tail/last element of a linked list
//Removing Kth element of a linked list
//Removing a given value from a linked list

// CASE 3 - Removing Kth element(head/tail or any random element) of a doubly linked list

// Time Complexity - O(K)

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

Node* deleteHead(Node* head) {

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

Node* deleteTail(Node* head) {

  // Edge case: if the linked list is empty or has only one element
  if (head == nullptr || head->next == nullptr) {
    return nullptr;
  }

  // Temporary pointer to traverse the linked list
  Node* temp = head;

  // Traverse to the last node
  while (temp->next != nullptr) {
    temp = temp->next;
  }

  // Save the new tail (previous node of the current tail)
  Node* newTail = temp->prev;

  // Update the prev pointer of the current tail to nullptr
  temp->prev = nullptr;

  // Update the next pointer of the new tail to nullptr
  newTail->next = nullptr;

  // Delete the current tail to free up memory
  delete temp;

  // Return the head of the linked list
  return head;
}


// Function to remove the Kth element of a doubly linked list
Node* removeKthElement(Node* head, int position) {
  // Check if the linked list is empty
  if (head == nullptr) {
    return nullptr;
  }

  // Temporary pointer to traverse the linked list
  Node* kNode = head;

  int cnt = 0;

  // Traverse to the Kth element
  while (kNode) {
    cnt++;

    if (cnt == position) {
      break;
    }

    kNode = kNode->next;
  }

  // Save the previous and next nodes of the Kth element
  Node* prevElNode = kNode->prev;
  Node* nextElNode = kNode->next;

  // Check if the Kth element is the only element in the list
  if (prevElNode == nullptr && nextElNode == nullptr) {
    return nullptr;
  } else if (prevElNode == nullptr) {
    // If Kth element is the head, delete head
    return deleteHead(head);
  } else if (nextElNode == nullptr) {
    // If Kth element is the tail, delete tail
    return deleteTail(head);
  }

  // Update the next pointer of the previous node to skip the Kth element
  prevElNode->next = nextElNode;
  // Update the prev pointer of the next node to skip the Kth element
  nextElNode->prev = prevElNode;

  // Update the prev and next pointers of the Kth element to nullptr
  kNode->prev = nullptr;
  kNode->next = nullptr;

  // Delete the Kth element to free up memory
  delete kNode;

  // Return the head of the updated linked list
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
  int k = 5;

  cout << "Linked List before removing Kth element "<< k << endl;
  print(head);

  cout << endl;


  // Remove the head of the linked list
  head = removeKthElement(head, k);

  cout << "Linked List after removing Kth element" << endl;
  print(head);

  return 0;
}

// OUTPUT
// Linked List before removing Kth element 1
// 100 12 141 452 21 
// Linked List after removing Kth element
// 12 141 452 21 

// Linked List before removing Kth element 5
// 100 12 141 452 21 
// Linked List after removing Kth element
// 100 12 141 452 

// Linked List before removing Kth element 4
// 100 12 141 452 21 
// Linked List after removing Kth element
// 100 12 141 21 