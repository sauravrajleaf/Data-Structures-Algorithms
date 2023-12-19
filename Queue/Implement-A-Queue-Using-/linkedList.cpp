// Implementing a queue using a linked list in C++ involves creating a simple linked list structure with pointers 
// to manage the front and rear of the queue. Each node of the linked list will hold the data and a pointer 
// to the next node.

#include<bits/stdc++.h>

using namespace std;

// Node structure for the linked list
class Node {
  public:
    int data;
    Node* next;

    Node(int data) {
      this->data = data;
      this->next = nullptr;
    }
};


// Queue class using linked list
class Queue {
  private:
    Node* front;
    Node* rear;

  public:
    //Constructor function
    Queue() {
      front = nullptr;
      rear = nullptr;
    }

    // Function to add an item to the queue
    void enqueue(int val) {
      Node* newNode = new Node(val);

      //check if the queue is empty
      if(rear == nullptr) {
        //if the queue is empty both front and rear will point to the first node
        front = rear = newNode;
        return;
      }

      rear->next = newNode;//insert at the back
      rear = newNode;//move the rear node to the last element

    }

    // Function to remove an item from queue
    int dequeue() {
      if(front == nullptr) {
        cout << "Queue is empty" << endl;
        return INT_MIN;
      }

      Node* temp = front;

      front = front->next;
      
      //if the last element was deleted front will point to null
      //in that case make sure, rear also points to null
      //this step is necessary otherwise there will be issues during insertion
      if(front == nullptr) {
        rear = nullptr;
      }

      int val = temp->data;

      //delete the front element
      delete temp;

      return val;
    }

    // Function to get front of queue
    int peek() {
      if(front == nullptr) {
        cout << "Queue is empty" << endl;
        return INT_MIN;
      }

      return front->data;
    }

    // Function to check if queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    void printQueue() {
      Node* temp = front;

      while(temp != NULL) {
        cout<<temp->data<<" ";

        temp = temp->next;
      }
    }

     // Destructor to clean up the queue
    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
    }

};

int main() {
  Queue myQueue;

  myQueue.enqueue(10);
  myQueue.enqueue(9);
  myQueue.enqueue(90);
  myQueue.enqueue(20);

  //Delete the front element
  cout << "Dequeued: " << myQueue.dequeue() << endl; // Should dequeue 10

  cout << "Front item: " << myQueue.peek() << endl;

  cout<<"Elements present in the queue"<<endl;
  myQueue.printQueue();  // Print queue contents after dequeue
  return 0;
}


// In this implementation:

// The Node class represents each element in the queue.
// The Queue class has two pointers, front and rear, pointing to the first and last nodes of the linked list, respectively.
// The enqueue method adds a new node to the end of the list.
// The dequeue method removes a node from the front of the list and returns its data.
// The peek method returns the data of the front node without removing it.
// The isEmpty method checks if the queue is empty.
// The destructor (~Queue) deallocates all the nodes in the queue to prevent memory leaks.
// This implementation ensures FIFO (First-In-First-Out) behavior typical of queues, with enqueue operations happening at the rear and dequeue operations at the front.