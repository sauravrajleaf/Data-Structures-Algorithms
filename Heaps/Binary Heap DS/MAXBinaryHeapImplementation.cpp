#include <bits/stdc++.h>
using namespace std;

class MaxBinaryHeap {
  public:
    int capacity; // Maximum number of elements in the heap
    int size;     // Current number of elements in the heap
    int *arr;     // Dynamic array to store heap elements
  
    // Constructor to initialize the binary heap with a given capacity
    MaxBinaryHeap(int cap) {
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

      // Fix the max heap property if it is violated
      while(k != 0 && arr[parent(k)] < arr[k]) {
        swap(arr[parent(k)], arr[k]);
        k = parent(k);
      }
    }

    // Function to get the maximum element from the heap
    int getMax() {
      return arr[0];
    }

    // Function to heapify a subtree with the root at given index
    void maxHeapify(int index) {
      int rightChild = right(index);
      int leftChild = left(index);

      int largest = index;

      // Find the largest among root, left child and right child
      if(leftChild < size && arr[leftChild] > arr[largest]) {
        largest = leftChild;
      }

      if(rightChild < size && arr[rightChild] > arr[largest]) {
        largest = rightChild;
      }

      // Swap and continue heapifying if root is not largest
      if(largest != index) {
        swap(arr[index], arr[largest]);
        maxHeapify(largest);
      }
    }

    // Function to extract the maximum element from the heap
    int extractMax() {
      if(size <= 0) {
        return INT_MAX;
      }

      if(size == 1) {
        size--;
        return arr[0];
      }
      
      // Move the max element to the end and reduce heap size
      swap(arr[0], arr[size - 1]);

      size--;
      maxHeapify(0);

      return arr[size];
    }

    // Function to decrease the value of key at a given index
    void decreaseKey(int index, int value) {
      arr[index] = value; // Assign the new value at the given index

      // Fix the max heap property if it is violated
      while(index != 0 && arr[parent(index)] < arr[index]) {
        swap(arr[parent(index)], arr[index]);
        index = parent(index);
      }
    }

    // Function to delete a node at a given index
    void deleteNode(int index) {
      decreaseKey(index, INT_MAX); // Decrease the value to the maximum possible
      extractMax(); // Remove the maximum element, which is now the one we decreased
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

  MaxBinaryHeap myMaxHeap(20);

  myMaxHeap.insert(10);
  myMaxHeap.insert(20);
  myMaxHeap.insert(30);
  myMaxHeap.insert(40);
  myMaxHeap.insert(50);
  myMaxHeap.insert(60);
  myMaxHeap.insert(5);

  myMaxHeap.print();

  cout<<"Get Max"<<endl;
  cout << "Max value is " << myMaxHeap.getMax() << endl;

  cout<<"Extract Max "<<endl;
  cout<<myMaxHeap.extractMax()<<endl;

  cout << "Max value is " << myMaxHeap.getMax() << endl;


  cout<<"After extracting the max"<<endl;
  myMaxHeap.print();

  int index = 4, newVal = 1;
  myMaxHeap.decreaseKey(index, newVal);

  cout<<"After decrease key operation for index "<<index<<" new val "<<newVal<<endl;
  myMaxHeap.print();


  myMaxHeap.deleteNode(index);
  cout<<"After delete operation for index "<<index<<endl;
  myMaxHeap.print();


  return 0;
}


