//4 cases - 
//Inserting head/first element of a linked list
//Inserting tail/last element of a linked list
//Inserting Kth element of a linked list
//Inserting a given value from a linked list

// CASE 4 - Inserting a given value in a linked list before a given value

// Time Complexity - O(K), K is the position of the new element linked list


#include <bits/stdc++.h>

using namespace std;

class Node {
  public:
  // Member variables
  int data;
  Node* next;

  // Constructor function
  public:
  Node(int data1, Node* next1) {
    data = data1;
    next = next1;
  }

  // Constructor function
  public:
  Node(int data1) {
    data = data1;
    next = nullptr;
  }

};

// Function to insert a new node before a specified element in the linked list
Node* insertBeforeAnElement(Node* head, int value, int insertBeforeVal) {
  // Edge case: if the linked list is empty
  if(head == NULL) {
    return NULL;
  }

  // If the desired element is the head, insert a new node at the head
  if(head->data == insertBeforeVal) {
    return new Node(value, head);
  }

  // Temporary pointer to traverse the linked list
  Node* temp = head;

  // Traverse the linked list
  while(temp->next != NULL) {
    // If the desired position is reached (one before the specified position)
    if(temp->next->data == insertBeforeVal) {
      // Create a new node with the given value and next pointing to the current next node
      Node* newElement = new Node(value, temp->next);

      // Update the next pointer of the current node to point to the new node
      temp->next = newElement;

      // Exit the loop after insertion
      break;
    }

    // Move to the next node
    temp = temp->next;
  }

  // Return the head of the updated linked list
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
  vector<int> arr = {45, 23, 12, 34, 2};

  // Convert the array to a linked list
  Node* head = convertArr2LL(arr);

  // Value to insert
  int value = 90;
  
  //insert new value before the value
  int insertBefore = 34;

  cout << "Linked List before inserting new element"<< endl;
  print(head);

  cout << endl;


  // Insert a new node at the specified position in the linked list
  head = insertBeforeAnElement(head, value, insertBefore);

  cout << "Linked List after inserting new element after value "<<insertBefore<< endl;
  print(head);

  return 0;
}

// OUTPUT
// // Value to insert
// int value = 90;
// //insert new value before the value
// int insertBefore = 2;
// Linked List before inserting new element
// 45 23 12 34 2 
// Linked List after inserting new element after value 2
// 45 23 12 34 90 2 


// // Value to insert
// int value = 90;
// //insert new value before the value
// int insertBefore = 45;
// Linked List before inserting new element
// 45 23 12 34 2 
// Linked List after inserting new element after value 45
// 90 45 23 12 34 2 


// // Value to insert
// int value = 90;
// //insert new value before the value
// int insertBefore = 12;
// Linked List before inserting new element
// 45 23 12 34 2 
// Linked List after inserting new element after value 12
// 45 23 90 12 34 2 