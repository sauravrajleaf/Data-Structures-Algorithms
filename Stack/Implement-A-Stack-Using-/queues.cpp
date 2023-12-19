// Implementing a stack using queues in C++ can be an interesting exercise. 
// A stack is a Last-In-First-Out (LIFO) structure, whereas a queue is a First-In-First-Out (FIFO) structure. 
// To simulate the behavior of a stack using queues, we need to manage the order of elements appropriately.

// One common approach is to use two queues. The key idea is to use one queue as the primary storage and 
// the other to help with the push operation. Here's a basic implementation:

#include<bits/stdc++.h>

using namespace std;

class Stack {
  private:
    queue<int> q1, q2;


  public:
    //Push an element onto the stack
    void push(int x) {

      q2.push(x);

      //if q1 is not empty
      //the push all the elements from q1 to q2
      while(!q1.empty()) {
        q2.push(q1.front());//this will maintain the elements in LIFO order

        q1.pop();
      }

      //now q2 has all the elements in the LIFO order
      queue<int> temp = q1;

      q1 = q2;
      q2 = temp;
    }

    int top() {
      if(q1.empty()) {
        return -1;
      }
      else return q1.front();
    }

    bool empty() {
      return q1.empty();
    }

    int pop() {
      if(q1.empty()) {
        cout<<"Stack is empty"<<endl;
        return -1;
      }

      int x = q1.front();
      q1.pop();//Deletes the front element

      return x;
    }


};

int main() {
    Stack myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    cout << "Top element: " << myStack.top() << endl; // Should be 3

    myStack.pop();
    cout << "Top element after pop: " << myStack.top() << endl; // Should be 2

    return 0;

}