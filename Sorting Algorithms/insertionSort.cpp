/*
************************************************************************************************************************************************************************************
<Title>
Iterative Insertion Sort using Array
************************************************************************************************************************************************************************************
<Introduction>
Insertion sort is a simple sorting algorithm that works similar to the way you sort playing cards in your hands. The array is virtually split into a sorted and an unsorted part. Values from the unsorted part are picked and placed at the correct position in the sorted part.
************************************************************************************************************************************************************************************
Time Complextiy ->
************************************
Average -> O(N^2)
************************************
Best -> O(N), when the array is already sorted
************************************
Worst -> O(N^2)
************************************************************************************************************************************************************************************
Space Complexity ->O(N)
************************************************************************************************************************************************************************************
Problem Link - https://www.codingninjas.com/studio/problems/insertion-sort_624381?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
Status - Accepted
************************************************************************************************************************************************************************************
Constraints :
0 <= N <= 10^3
0 <= arr[i] <= 10^5
Time Limit: 1 sec
************************************************************************************************************************************************************************************
<Information Sources>
https://www.geeksforgeeks.org/insertion-sort/
************************************************************************************************************************************************************************************
*/

#include <bits/stdc++.h>

using namespace std;


void insertionSort(int arr[], int n)
{
  // write your code here

  //write your code here
    //Insertion Sort - In every iteration, the element at index i is selected and it is placed at its correct position in a sorted array.
    //Time Complexity - O(N^2)
    //Space Complexity - O(1)
    //Best Case - O(N) When the array is already sorted

    //i keeps track of current element
    //This loops keep moving right after everything before this loop is sorted
    for(int i=0;i<=n-1;i++) {
        int j = i;//element at position j will be placed at its correct position
        
        //This loop places the current element at its correct position
        //therefore the element that it points at
        //after this loop end
        //that element is moved to its correct position
        //and the array from 0 to i is sorted
        while(j>0 && arr[j-1] > arr[j]) {
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            // swap(arr[j-1],arr[j]);
            j--;
        }
    }
}

int main()
{
  int arr[] = {10, 24, 1, 2, 0, 12, 2};

  cout << "Before Sorting:" << endl;
  for (int i = 0; i < 7; i++)
    cout << arr[i] << "\t";
  cout << endl;
  insertionSort(arr, 7);

  cout << "After Sorting:" << endl;
  for (int i = 0; i < 7; i++)
    cout << arr[i] << "\t";
  cout << endl;
}