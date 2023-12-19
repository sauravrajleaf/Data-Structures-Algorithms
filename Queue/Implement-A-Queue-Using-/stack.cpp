#include<bits/stdc++.h>

using namespace std;

class Queue {
  private:
    stack<int> s1, s2;
  public:

    void enQueue(int x)
    {
        // Move all elements from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
 
        // Push item into s1
        s1.push(x);
 
        // Push everything back to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }

      int front = s1.top();
    }
 
    // Dequeue an item from the queue
    int deQueue()
    {
        // if first stack is empty
        if (s1.empty()) {
            return -1;
        }
 
        // Return top of s1
        int x = s1.top();
        s1.pop();
        return x;
    }


     // Function to get front of queue
    int peek() {
        if (s1.empty()) {
            cout << "Queue is empty" << endl;
            return INT_MIN;
        }
        return s1.top();
    }

    // Function to check if queue is empty
    bool isEmpty() {
        return s1.empty();
    }

    bool printQueue() {
      stack<int> temp = s1;
     if (temp.empty()) {
            cout << "Queue is empty" << endl;
            return INT_MIN;
        }

      while(!temp.empty()) {
        cout<<temp.top()<<" ";

        temp.pop();
      }
      return true;
    }
};

int main() {
   Queue myQueue;
  myQueue.enQueue(1);
  myQueue.enQueue(2);
  myQueue.enQueue(3);
  
  cout << "Dequeued Front item: " << myQueue.deQueue() << endl; // Should dequeue 10
  cout << "Front item: " << myQueue.peek() << endl;
  cout << "Check if queue is empty: " << myQueue.isEmpty() << endl;

  cout<<"All elements in the Queue"<<endl;
  myQueue.printQueue();
}

// enQueue Function:

// This function moves all elements from s1 to s2, pushes the new element onto s1, and then moves all elements back from s2 to s1.
// The purpose is to ensure that the oldest element is always at the top of s1, so it can be dequeued first, maintaining the FIFO order of the queue.
// deQueue Function:

// This function pops and returns the top element from s1, which is the front of the queue.
// peek Function:

// Returns the element at the front of the queue without removing it, which is the top element of s1.
// isEmpty Function:

// Checks if the queue (represented by s1) is empty.
// printQueue Function:

// This function prints all elements in the queue. 