#include<bits/stdc++.h>

using namespace std;

#define MAX 1000 

class Stack {
  int top;

  public:
    int arr[MAX]; //max size of array/stack
    
    //Construtor function
    //This will be called when a new Stack object is instantiated
    Stack() {
      top = -1;
    }

    bool push(int x);//x-> the value to be pushed

    int pop(); //this will delete the top element

    int peek();//returns the top element

    bool isEmpty(); //returns true if empty else false

};

// Out-of-Class Definition
// :: - Scope Resolution Operator
bool Stack::push(int x) {
  
  //if the max size of stack has already reached
  if(top >= (MAX - 1)) {
    cout<<"Stack Overflow"<<endl;
    return false;
  }

  else {
    
    //increment top value, so that it points to the new value being pushed
    top++;
    arr[top] = x;
    cout<<x<<" is pushed onto stack"<<endl;
    return true;
  }
}

//This method will return the tope element of the stack
int Stack::peek() {
  //because we started from top = -1
  if(top < 0) {
    cout<<"Stack is empty"<<endl;
    return 0;
  }
  else {
    int x = arr[top];
    return x;
  }
    
}

int Stack::pop() {
  //because we started from top = -1
  if(top < 0) {
    cout<<"Stack is empty"<<endl;
    return 0;
  }

  else {
    //basically we are decrementing the value of top to point at the previous value in the array
    int x = arr[top--];
    return x;

  }
}

bool Stack::isEmpty() {
  return top < 0;
} 



int main() {
  
  class Stack s;//instantiating the Stack class, creating a new Stack class object s

    //PUSH OPERATION
    s.push(10); 
    s.push(20); 
    s.push(30); 

    //TOP OPERATION
    cout<<"Top element of Stack is "<<s.peek()<<endl;

    //POPPED LAST ELEMENT
    cout << s.pop() << " Popped from stack\n"; 

    //TOP element updated
    cout<<"Top element of Stack is "<<s.peek()<<endl;

    s.push(40); 
    s.push(50); 

    
    cout<<"Elements present in the stack"<<endl;
    //Printing all the elements present in the stack
    while(!s.isEmpty()) {

      cout<<s.peek()<<endl;

      //Remove the top element from stack
      s.pop();
    }

    return 0;
}



