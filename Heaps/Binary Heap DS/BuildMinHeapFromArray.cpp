// Time Complexity: O(N) - FOr detailed analysis checkout gfg heaps video tutorial
// Auxiliary Space: O(N) (Recursive Stack Space)


// C++ program for building Heap from Array

#include <bits/stdc++.h>

using namespace std;

// To heapify a subtree rooted with node i which is
// an index in arr[]. N is size of heap
void heapify(int arr[], int N, int index)
{
	int smallest = index; // Initialize smallest as root
	int leftChild = 2 * index + 1; // left = 2*index + 1
	int rightChild = 2 * index + 2; // right = 2*index + 2

	// If left child is larger than root
	if (leftChild < N && arr[leftChild] < arr[smallest])
		smallest = leftChild;

	// If right child is larger than smallest so far
	if (rightChild < N && arr[rightChild] < arr[smallest])
		smallest = rightChild;

	// If smallest is not root
	if (smallest != index) {
		swap(arr[index], arr[smallest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, N, smallest);
	}
}

// Function to build a Min-Heap from the given array
void buildHeap(int arr[], int N)
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

// A utility function to print the array
// representation of Heap
void printHeap(int arr[], int N)
{
	cout << "Array representation of Heap is:\n";

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
	buildHeap(arr, N);
	printHeap(arr, N);


	return 0;
}

// OUTPUT
// Array representation of Heap is:
// 1 2 3 5 10 15 4 
