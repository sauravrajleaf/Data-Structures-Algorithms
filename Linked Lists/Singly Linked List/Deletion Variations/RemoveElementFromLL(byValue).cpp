//4 cases - 
//Removing head/first element of a linked list
//Removing tail/last element of a linked list
//Removing Kth element of a linked list
//Removing a given value from a linked list

// CASE 4 - Removing Element(head/tail or any random element) of a linked list whose value is given

// Time Complexity - 
// Best - O(1) - If the element is head element
// Average - O(N/2) - If the element is in between
// Worst - O(N) - If the element is at the last position

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

// Function to remove the element of a linked list
Node* removeElement(Node* head, int value) {
  // Check if the linked list is empty (edge case)
  if(head == NULL) return NULL;

  // Removing the head (edge case)
  if(value == head->data) {
    // Temporarily store the current head
    Node* temp = head;

    // Move the head to the next node
    head = head->next;

    // Delete the original head to free up memory
    delete temp;

    return head;
  }

  // Temporarily store the current head
  Node* temp = head;

  // Initialize a pointer to the previous node
  Node* prev = NULL;

  // Traverse the linked list
  while(temp != NULL) {
    // If the desired value is found
    if(temp->data == value) {
      // Update the next pointer of the previous node to skip the current node
      prev->next = temp->next;

      // Delete the current node to free up memory
      delete temp;

      // Exit the loop after removal
      break;
    }

    // Move the pointers to the next nodes
    prev = temp;
    temp = temp->next;
  }

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

  cout << "Linked List before removing element" << endl;
  print(head);

  cout << endl;

  // Remove the Kth element of the linked list
  head = removeElement(head, 100);

  cout << "Linked List after removing element" << endl;
  print(head);

  return 0;
}

//OUTPUT
// element = 100
// Linked List before removing Kth element
// 1 10 100 12 2 8 
// Linked List after removing Kth element
// 1 10 12 2 8 
