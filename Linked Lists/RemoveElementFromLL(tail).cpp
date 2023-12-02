//4 cases - 
//Removing head/first element of a linked list
//Removing tail/last element of a linked list
//Removing Kth element of a linked list
//Removing a given value from a linked list

// CASE 2 - Removing tail/last element of a linked list


// Time Complexity - O(N), N is the number of elements in the linked list


#include <bits/stdc++.h>

using namespace std;

// Node class for a linked list
class Node {
  public:
  int data;
  Node* next;

  // Constructor with both data and next pointer
  Node(int data1, Node* next1) {
    data = data1;
    next = next1;
  }

  // Constructor with only data (default next pointer is nullptr)
  Node(int data1) {
    data = data1;
    next = nullptr;
  }

};

// Function to remove the tail/last element of a linked list
Node* removesTail(Node* head) {
  // Check if the linked list is empty or has only one element (edge case)
  if(head == NULL || head->next == NULL) return NULL;

  // Temporarily store the current head
  Node* temp = head;

  // Traverse the linked list until the second-to-last node
  while(temp->next->next != NULL) {
    temp = temp->next;
  }

  // Delete the last node to free up memory
  delete temp->next;

  // Set the next pointer of the second-to-last node to nullptr
  //making it the new tail
  temp->next = nullptr;

  // Return the updated head
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
  for(int i = 1; i < arr.size(); i++) {
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
  vector<int> arr = {1, 10, 100, 12, 2, 8};

  // Convert the array to a linked list
  Node* head = convertArr2LL(arr);

  cout << "Linked List before removing tail" << endl;
  print(head);

  cout << endl;

  // Remove the tail of the linked list
  head = removesTail(head);

  cout << "Linked List after removing tail" << endl;
  print(head);

  return 0;
}

//OUTPUT
// Linked List before removing tail
// 1 10 100 12 2 8 
// Linked List after removing tail
// 1 10 100 12 2 
