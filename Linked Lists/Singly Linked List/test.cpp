#include <bits/stdc++.h>
using namespace std;

// Node class for a linked list
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

Node* reverseLinkedList(Node* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }

    Node* prev = NULL;

    Node* curr = head;

    while(curr != NULL) {
        Node* ahead = curr->next;

        curr->next = prev;

        prev = curr;

        curr = ahead;
    }

    return prev;
}



Node* addOne(Node* head) {

   //reverse the linked list
    head = reverseLinkedList(head);

    Node* temp= head; 

    // while(temp!=NULL) {
    //     cout<<temp->data<<" ";
    //     temp = temp->next;
    // }

   int carry = 0;
    int num = 0;

    //O(N)
     while(temp != NULL) {
        num = temp->data;

        num+=1;

        if(num >= 10) {
            carry = 1;
            temp->data = 0;
        }
        else {
            temp->data = num;
            // carry = 0;
            break;//as there is no carry so there will be change in only one digit value
        }

        temp = temp->next;
    }
    cout<<"carry "<<carry<<endl;
    //if there is a carry that means a new head will be added
    if(carry == 1) {
        Node* newHead = new Node(1);//create a new node for the new head

        head = reverseLinkedList(head);//reverse the existing LL

        newHead->next = head;//point the new head to the existing head

        return newHead;//return the new head

        //reverse the linked list
        
    }

    //if there is no carry that means
    //we just have to reverse the list and return
    head = reverseLinkedList(head);

    return head;


    // // Reverse the linked list
    // head = reverseLinkedList(head);

    // Node* temp = head;
    // int carry = 1; // Initialize carry with 1 for adding 1

    // while (temp != NULL) {
    //     int num = temp->data + carry;
    //     carry = num / 10;
    //     temp->data = num % 10;
    //     temp = temp->next;
    // }

    // // If there is a carry after the loop, add a new node
    // if (carry > 0) {
    //     Node* newHead = new Node(carry);

    //     // Reverse the linked list again
    //     head = reverseLinkedList(head);

    //     newHead->next = head;
    //     head = newHead;

    //     return newHead;
    // }

    // // Reverse the linked list again
    // head = reverseLinkedList(head);

    // return head;
}


Node * removeDuplicates(Node *head)
{
    // Write your code here

    Node* temp = head;
    Node* ahead = head;//element next of curr element
    
    while(temp!=NULL) {
        

        ahead = temp->next;
        
        //delete current node
        if(temp->data == ahead->data) {

            if(temp == head) {
                head = head->next;
            }

            Node* prevNode = temp->prev;
            Node* nextNode = temp->next;
            
            //check if its not the head node
            if(prevNode!=NULL) prevNode->next = nextNode;

            //check if its not the tail node
            if(nextNode!=NULL) nextNode->prev = prevNode;

            temp->next = NULL;
            temp->prev = NULL;
            
            delete temp;

        }

        temp = temp->next;
    }

    return head;
}



// Function to print the elements of the doubly linked list
void print(Node* head) {
  Node* temp = head;

  while (temp) {
    cout << temp->data << " ";
    temp = temp->next;
  }
}

int main() {
  // Example array
  vector<int> arr = {1,2, 2, 2, 3};

  // Convert the array to a linked list
  Node* head = convertArr2DLL(arr);

  head = removeDuplicates(head); 

  print(head);
}