// Implementing a queue using an array in C++ involves managing a fixed-size array with two pointers or indices 
// to track the front and rear of the queue. This implementation requires handling the boundary conditions carefully, 
// especially when the queue is full or empty.

// This implementation demonstrates a basic circular queue using an array. 
// Handling corner cases like queue overflow (when trying to add to a full queue) and 
// underflow (when trying to remove from an empty queue) is essential for robustness.

#include <bits/stdc++.h>

using namespace std;

class Queue {
  private:
    int front, rear, size;
    unsigned capacity;
    int* array;


  public:
    //Constructor to create a queue of given capacity
    Queue(unsigned capacity) {
      this->capacity = capacity;
      front = size = 0;
      rear = capacity = -1;

      array = new int[capacity];// After this assignment, array points to the first element of this dynamically allocated space.
    }

    // Function to add an item to the queue
    void enqueue(int item) {
      //check if the queue is already full
      if(size == capacity) {
        cout<<"Queue Overflow"<<endl;
        return;
      }
      
      rear = (rear + 1) % capacity;//This edgecase is the whole thing connecting the queue front and back
      
      array[rear] = item;
      size++;
      cout << item << " enqueued to queue" << endl;
    }

     // Function to remove an item from queue
    int dequeue() {
        if (size == 0) {
            cout << "Queue Underflow" << endl;
            return INT_MIN;
        }
        int item = array[front];
        front = (front + 1) % capacity;
        size--;
        return item;
    }


    // Function to get front of queue
    int frontItem() {
        if (size == 0) {
            cout << "Queue is Empty" << endl;
            return INT_MIN;
        }
        return array[front];
    }

    // Function to get rear of queue
    int rearItem() {
        if (size == 0) {
            cout << "Queue is Empty" << endl;
            return INT_MIN;
        }
        return array[rear];
    }

    void printQueue() {
    if (size == 0) {
        cout << "Queue is empty" << endl;
        return;
    }

    int current = front;
    cout << "Queue elements: ";
    for (int i = 0; i < size; i++) {
        cout << array[current] << " ";
        current = (current + 1) % capacity;//using new var current because we don't want front value to change
    }
    cout << endl;
  }

    // Destructor
    ~Queue() {
        delete[] array;
    }
};


int main() {
  Queue q(5);

  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);
  q.enqueue(40);
  q.enqueue(50);
  q.enqueue(60);
  q.enqueue(70);

  cout << q.dequeue() << " dequeued from queue" << endl;
  cout << "Front item is " << q.frontItem() << endl;
  cout << "Rear item is " << q.rearItem() << endl;

  q.enqueue(70);
 cout << "Rear item is " << q.rearItem() << endl;
  cout<<"Elements present in the queue"<<endl;
  q.printQueue();  // Print queue contents after dequeue
  return 0;
}


// In this implementation:

// The Queue class contains an array to store queue elements, an integer to hold the capacity, 
// and two integers to track the front and rear positions.
// The enqueue function adds an item to the rear of the queue.
// The dequeue function removes an item from the front of the queue.
// The frontItem and rearItem functions return the front and rear items of the queue, respectively.
// The circular queue approach is used where indices wrap around when they reach the end of the array.
// The constructor initializes the queue, and the destructor releases the allocated memory.