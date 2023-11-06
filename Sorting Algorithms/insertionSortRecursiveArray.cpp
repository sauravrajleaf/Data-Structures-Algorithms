/*
************************************************************************************************************************************************************************************
<Title>
Recursive Insertion Sort using Array
************************************************************************************************************************************************************************************
<Introduction>
Insertion sort is a simple sorting algorithm that works similar to the way you sort playing cards in your hands. The array is virtually split into a sorted and an unsorted part. Values from the unsorted part are picked and placed at the correct position in the sorted part.
************************************************************************************************************************************************************************************
Time Complextiy ->
************************************
Average -> O(N^2)
************************************
Best -> O(N)
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

void insertionSortRecurs(int arr[], int n, int idx)
{

  if (idx == n)
    return;

  int j = idx; // element at position j will be placed at its correct position

  while (j > 0 && arr[j - 1] > arr[j])
  {
    int temp = arr[j - 1];
    arr[j - 1] = arr[j];
    arr[j] = temp;
    // swap(arr[j-1],arr[j]);
    j--;
  }
  idx++;
  return insertionSortRecurs(arr, n, idx);
}

void insertionSort(int arr[], int n)
{
  // write your code here

  if (n <= 0)
    return;
  int idx = 0;
  insertionSortRecurs(arr, n, idx);
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