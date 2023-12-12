// Time Complexity -  O(N^2)
// Space Complexity - O(N)

// Sorting a stack recursively in ascending order

#include <bits/stdc++.h>

using namespace std;

void insertTop(stack<int>& st, int topElement) {
  if(st.empty() || topElement < st.top()) {
    st.push(topElement);
    return;
  }

  int temp = st.top();
  st.pop();
  
  insertTop(st, topElement);
  st.push(temp);
}

void sortStack(stack<int>& st) {
  
  if(!st.empty()) {
    int topElement = st.top();

    st.pop();

    sortStack(st);

    insertTop(st,topElement);
  }

}

int main() {
  stack<int> st;
  st.push(34);
  st.push(3);
  st.push(31);
  st.push(98);
  st.push(92);
  st.push(23);

  cout<<"Before Sorting\n";

  while(!st.empty()) {
    cout<<st.top()<<" ";
    st.pop();
  }
  cout<<endl;
  st.push(34);
  st.push(3);
  st.push(31);
  st.push(98);
  st.push(92);
  st.push(23);

  cout<<"After Sorting\n";

  sortStack(st);

  while(!st.empty()) {
    cout<<st.top()<<" ";
    st.pop();
  }

  cout<<endl;
  
}