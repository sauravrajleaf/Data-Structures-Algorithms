#include <bits/stdc++.h>

using namespace std;


// Definition of a node in the stack
class StackNode {
  public:
    int data;
    StackNode* next;
};

class Stack {
  private:
    StackNode* top;//declared a variable to type StackNode

  public:
    Stack() {
      top = NULL;
    }

    //Function to add an element in the stack
    void push(int val) {
      StackNode* newNode = new StackNode();
      newNode->data = val;
      newNode->next = top;//point the new node to prev node
      top = newNode;//make the new node as the top element(LIFO)
    }

    // Function to check if the stack is empty
    bool isEmpty() {
      return top == NULL;
    }

    //Function to remove an element from the stack
    int pop() {
      if(isEmpty()) {
        cout<<"Stack Underflow"<<endl;
        return 0;
      }
      StackNode* temp = top;
      // update the top to the next node, next node will be providing to the prev value - do dry run to understand
      top = top->next;

      //store the data to be deleted
      int popped = temp->data;  
      
      delete temp;
      return popped;

    }

    int peek() {
      if(isEmpty()) {
        cout<<"Stack Underflow"<<endl;
        return 0;
      }
      return top->data;
    }

};



int main() {
  Stack  myStack;

  myStack.push(10);
  myStack.push(12);
  myStack.push(8);

 cout << "Top element is: " << myStack.peek() << endl;

 cout<<"Deleting the current top element"<<endl;
 cout<<"Deleted "<<myStack.pop()<<endl;

 cout<<"Elements present in the stack"<<endl;

 while(!myStack.isEmpty()) {
  cout<<myStack.peek()<<endl;

  myStack.pop();
 }

 return 0;
}