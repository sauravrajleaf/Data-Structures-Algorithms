// Time Complexity - 
// Best - O(N) -> If the element is found at the first index
// Average - O(N) -> If the element is found at somewhere in the middle
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

// Function to calculate the length of a linked list
int lengthOfALL(Node* head) {
  int cnt = 0;

  // Traverse the linked list and count the number of nodes
  Node* temp = head;
  while (temp) {
    temp = temp->next;
    cnt++;
  }

  return cnt;
}

int main() {
  // Example array
  vector<int> arr = {1, 5, 6, 3};

  // Convert the array to a linked list
  Node* head = convertArr2LL(arr);

  // Print the length of the linked list
  cout << "Length of the linked list: " << lengthOfALL(head) << endl;

  return 0;
}

// OUTPUT
// Length of the linked list: 4
