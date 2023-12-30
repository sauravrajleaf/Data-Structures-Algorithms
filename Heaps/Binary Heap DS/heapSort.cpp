// Time Complexity: O(NLogN) - FOr detailed analysis checkout gfg heaps video tutorial
// Auxiliary Space: O(LogN) (Recursive Stack Space)

// Steps involved in heap sort
// 1. Make a max heap(if sorting the array in increasing order)
// 2. For each parent node, swap it with the last node and call heapify
// 3. keep repeating step 2 until there is only one node i.e, root node left

#include <bits/stdc++.h>

using namespace std;

// To heapify a subtree rooted with node i which is
// an index in arr[]. N is size of heap
void heapify(int arr[], int N, int index)
{
	int largest = index; // Initialize largest as root
	int leftChild = 2 * index + 1; // left = 2*index + 1
	int rightChild = 2 * index + 2; // right = 2*index + 2

	// If left child is larger than root
	if (leftChild < N && arr[leftChild] > arr[largest])
		largest = leftChild;

	// If right child is larger than largest so far
	if (rightChild < N && arr[rightChild] > arr[largest])
		largest = rightChild;

	// If largest is not root
	if (largest != index) {
		swap(arr[index], arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, N, largest);
	}
}

// Function to build a Min-Heap from the given array
void buildMaxHeap(int arr[], int N)
{
	// Index of last non-leaf node starting from the bottom
  //we only travel to non leaf nodes(parent nodes)
	int startIdx = (N / 2) - 1;

	// Perform reverse level order traversal
	// from last non-leaf node and heapify
	// each node
	for (int i = startIdx; i >= 0; i--) {
		heapify(arr, N, i);
	}
}

void heapSort(int arr[], int n) {
  
  buildMaxHeap(arr, n);

  for (int i=n-1; i>0; i--) 
	{ 
		swap(arr[0], arr[i]);
		heapify(arr, i, 0); 
	} 
}

// A utility function to print the array
// representation of Heap
void printHeap(int arr[], int N)
{
	cout << "Array representation of Max Heap is:\n";

	for (int i = 0; i < N; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

// Driver Code
int main()
{

	int arr[] = {10, 5, 15, 1, 2, 3, 4};

	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	heapSort(arr, N);
	printHeap(arr, N);


	return 0;
}

// OUTPUT
// Array representation of Max Heap is:
// 15 5 10 1 2 3 4 
