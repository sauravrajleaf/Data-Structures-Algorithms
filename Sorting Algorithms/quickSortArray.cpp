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

/*
  The function is called with the parameters:
  quickSort(input, 0, size - 1);

*/

int partitionIndexFunc(int input[], int start, int end)
{
  // Write your code here

  int pivot = input[start]; // set first element as pivot
  int i = start;
  int j = end;

  // Loop goes on until low and high has crossed.
  //  Meaning when low crosses high all the elements are already placed in the order required.
  while (i < j)
  {
    // Loop continues until an element greater than pivot is found
    while (input[i] <= pivot && i <= end - 1)
    {
      i++;
    }

    while (input[j] > pivot && j >= start + 1)
    {
      j--;
    }

    if (i < j)
    {
      swap(input[i], input[j]);
    }
  }

  swap(input[start], input[j]);

  return j;
}

void quickSort(int input[], int start, int end)
{
  /*
    Don't write main().
    Don't read input, it is passed as function argument.
    Change in the given array itself.
    Taking input and printing output is handled automatically.
  */

  if (start < end)
  {
    int partitionIndex = partitionIndexFunc(input, start, end);
    quickSort(input, start, partitionIndex - 1);
    quickSort(input, partitionIndex + 1, end);
  }
}

int main()
{
  // int input[] = {100, 23, 35, 0, 99, 54};
  // int n = sizeof(input) / sizeof(input[0]);

  int n;
  cin >> n;
  int input[n];
  for (int i = 0; i < n; i++)
    cin >> input[i];

  int start = 0;
  int end = n - 1;

  // Print array before sorting
  cout << "Before Sorting:" << endl;

  for (int i = 0; i < n; i++)
    cout << input[i] << "\t";

  cout << endl;

  quickSort(input, start, end);

  // Print array after sorting
  cout << "After Sorting:" << endl;

  for (int i = 0; i < n; i++)
    cout << input[i] << "\t";

  cout << endl;

  return 0;
}
