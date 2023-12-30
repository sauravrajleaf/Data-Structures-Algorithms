#include <bits/stdc++.h>
using namespace std;

class MinBinaryHeap {
  public:
    int capacity; // Maximum number of elements in the heap
    int size;     // Current number of elements in the heap
    int *arr;     // Dynamic array to store heap elements
  
    // Constructor to initialize the binary heap with a given capacity
    MinBinaryHeap(int cap) {
      capacity = cap;
      size = 0;
      arr = new int[capacity];
    }

    // Function to get index of left child of a node at index i
    int left(int i) { 
      return (2*i + 1); 
    }

    // Function to get index of right child of a node at index i
    int right(int i) { 
      return (2*i + 2); 
    }

    // Function to get index of parent of a node at index i
    int parent(int i) { 
      return (i-1)/2; 
    }

    // Function to insert a new element into the heap
    void insert(int data) {
      if(size == capacity) {
        cout << "Binary Heap Overflown" << endl;
        return;
      }

      // Insert the new element at the end of the heap
      arr[size] = data;
      int k = size;
      size++;

      // Fix the min heap property if it is violated
      while(k != 0 && arr[parent(k)] > arr[k]) {
        swap(arr[parent(k)], arr[k]);
        k = parent(k);
      }
    }

    // Function to get the minimum element from the heap
    int getMin() {
      return arr[0];
    }

    // Function to heapify a subtree with the root at given index
    void minHeapify(int index) {
      int rightChild = right(index);
      int leftChild = left(index);

      int smallest = index;

      // Find the smallest among root, left child and right child
      if(leftChild < size && arr[leftChild] < arr[smallest]) {
        smallest = leftChild;
      }

      if(rightChild < size && arr[rightChild] < arr[smallest]) {
        smallest = rightChild;
      }

      // Swap and continue heapifying if root is not smallest
      if(smallest != index) {
        swap(arr[index], arr[smallest]);
        minHeapify(smallest);
      }
    }

    // Function to extract the minimum element from the heap
    int extractMin() {
      if(size <= 0) {
        return INT_MAX;
      }

      if(size == 1) {
        size--;
        return arr[0];
      }
      
      // Move the minimum element to the end and reduce heap size
      swap(arr[0], arr[size - 1]);

      size--;
      minHeapify(0);

      return arr[size];
    }

    // Function to decrease the value of key at a given index
    void decreaseKey(int index, int value) {
      arr[index] = value; // Assign the new value at the given index
      // Fix the min heap property if it is violated
      while(index != 0 && arr[parent(index)] > arr[index]) {
        swap(arr[parent(index)], arr[index]);
        index = parent(index);
      }
    }

    // Function to delete a node at a given index
    void deleteNode(int index) {
      decreaseKey(index, INT_MIN); // Decrease the value to the minimum possible
      extractMin(); // Remove the minimum element, which is now the one we decreased
    }

    // Function to print the elements of the heap
    void print() { 
      for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
      }
      cout<<endl;
    }
};

int main() {

  MinBinaryHeap myMinHeap(20);

  myMinHeap.insert(10);
  myMinHeap.insert(20);
  myMinHeap.insert(30);
  myMinHeap.insert(40);
  myMinHeap.insert(50);
  myMinHeap.insert(60);
  myMinHeap.insert(5);

  myMinHeap.print();

  // cout<<myMinHeap.arr[myMinHeap.right(0)]<<endl;
  cout<<"Get Min"<<endl;
  cout << "Min value is " << myMinHeap.getMin() << endl;

  cout<<"Extract Min "<<endl;
  cout<<myMinHeap.extractMin()<<endl;

  cout << "Min value is " << myMinHeap.getMin() << endl;


  cout<<"After extracting the min"<<endl;
  myMinHeap.print();

  int index = 4, newVal = 1;
  myMinHeap.decreaseKey(index, newVal);

  cout<<"After decrease key operation for index "<<index<<" new val "<<newVal<<endl;
  myMinHeap.print();


  myMinHeap.deleteNode(index);
  cout<<"After delete operation for index "<<index<<endl;
  myMinHeap.print();


  return 0;
}


