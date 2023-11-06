/*
************************************************************************************************************************************************************************************
<Title>
Quick Sort using Vector in C++
************************************************************************************************************************************************************************************
<Introduction>
Quick Sort is a divide-and-conquer algorithm like the Merge Sort. But unlike Merge sort, this algorithm does not use any extra array for sorting(though it uses an auxiliary stack space). So, from that perspective, Quick sort is slightly better than Merge sort.

This algorithm is basically a repetition of two simple steps that are the following:

1.Pick a pivot and place it in its correct place in the sorted array.
2.Shift smaller elements(i.e. Smaller than the pivot) on the left of the pivot and larger ones to the right.
************************************************************************************************************************************************************************************
<Time Complextiy> ->
The following recurrence relation can be written for Quick sort :
F(n) = F(k) + F(n-1-k)
Here k is the number of elements smaller or equal to the pivot and n-1-k denotes elements greater than the pivot.
************************************
<Average> -> O(N*logN), where N = size of the array. Reason: At each step, we divide the whole array, for that logN and n steps are taken for the partition() function, so overall time complexity will be N*logN.
************************************
<Best> -> O(N*logN) This case occurs when the pivot is the middle element or near to middle element of the array.
Recurrence :
F(n) = 2F(n/2)
************************************
<Worst> -> O(N^2) This case occurs when the pivot is the greatest or smallest element of the array. If the partition is done and the last element is the pivot, then the worst case would be either in the increasing order of the array or in the decreasing order of the array.
Recurrence:
F(n) = F(0)+F(n-1)  or  F(n) = F(n-1) + F(0)
Worst Case Time complexity:  O(N^2)
************************************************************************************************************************************************************************************
<Space Complexity> -> O(1) + O(N) auxiliary stack space. O(1), if we don’t consider the recursive stack space. If we consider the recursive stack space then, in the worst case quicksort could make O(N).
************************************************************************************************************************************************************************************
<Problem Link> - https://www.codingninjas.com/studio/problems/quick-sort_5844?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
Status - Accepted
************************************************************************************************************************************************************************************
<Constraints> :
1 <= N <= 10^3
0 <= input[i] <= 10^9
************************************************************************************************************************************************************************************
<Information Sources>
https://takeuforward.org/data-structure/quick-sort-algorithm/
https://www.geeksforgeeks.org/quick-sort/
************************************************************************************************************************************************************************************
*/
#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
  int pivot = arr[low];
  int i = low;
  int j = high;

  // Loop goes on until low and high has crossed.
  //  Meaning when low crosses high all the elements are already placed in the order required.
  while (i < j)
  {
    // Loop continues until an element greater than pivot is found
    while (arr[i] <= pivot && i <= high - 1)
    {
      i++;
    }

    // Loop continues until an element smaller than the pivot is found
    while (arr[j] > pivot && j >= low + 1)
    {
      j--;
    }

    // arr[i] -> represents element that is greater than the pivot and is on the left of pivot
    // arr[j] -> represents element that is smaller than the pivot and is on the right of pivot
    // Quick sort algorithm states to move all the smallers elements to left and larger to right
    // swapping arr[i](greater) which is on left with arr[j](smalller) which is on the right
    if (i < j)
      swap(arr[i], arr[j]);
  }

  // Placing the pivot at its correct position
  // Swapping pivot with the last element of left subarray which contains the smaller elements
  // By this we made sure that the pivot element is placed at the correct position
  swap(arr[low], arr[j]);

  // Return the partition index where the pivot element is
  // Next partition will be start from left and right of the pivot(exclusive)
  // This same process will keep happening for all the subarrays until
  // the low < high -> meaning only one element remains in the subarray which in itself is sorted
  return j;
}

void qs(vector<int> &arr, int low, int high)
{
  if (low < high)
  {
    int pIndex = partition(arr, low, high);
    qs(arr, low, pIndex - 1);
    qs(arr, pIndex + 1, high);
  }
}

vector<int> quickSort(vector<int> arr)
{
  qs(arr, 0, arr.size() - 1);
  return arr;
}

int main()
{
  // vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3};

  // int n = arr.size();
  int n;
  cin >> n;
  cout << n << endl;
  vector<int> arr(n);

  // Taking input in vector
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << "Before Using quick Sort: " << endl;
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  // Calling quickSort function which returns the sorted vector
  arr = quickSort(arr);

  cout << "After Using quick sort: "
       << "\n";
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << "\n";
  return 0;
}