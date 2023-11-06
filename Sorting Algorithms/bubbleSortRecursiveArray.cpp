/*
************************************************************************************************************************************************************************************
<Title>
Recursive Bubble Sort using Array
************************************************************************************************************************************************************************************
<Introduction>
Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.
************************************************************************************************************************************************************************************
Time Complextiy ->
************************************
Average -> O(N^2)
************************************
Best -> O(N) Only if the array is already sorted and logic to exit in one go is implemented.
************************************
Worst -> O(N^2)
************************************************************************************************************************************************************************************
Space Complexity ->O(N) Recursive bubble sort runs on O(N) auxiliary space complexity whereas iterative bubble sort runs on O(1) auxiliary space complexity.
************************************************************************************************************************************************************************************
Problem Link - https://practice.geeksforgeeks.org/problems/bubble-sort/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
               https://www.codingninjas.com/studio/problems/bubble-sort_624380?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
Status - Accepted
************************************************************************************************************************************************************************************
Constraints :
1 <= N <= 10^3
0 <= arr[i] <= 10^9
Time Limit: 1 sec
************************************************************************************************************************************************************************************
<Information Sources>
https://www.geeksforgeeks.org/recursive-bubble-sort/
************************************************************************************************************************************************************************************
*/

#include <bits/stdc++.h>

using namespace std;

void bubbleSort(int arr[], int n)
{
  // write your code here

  // Base Case
  if (n == 1)
    return;

  int didSwap = 0;
  // Move the max element to the end
  for (int i = 0; i < n - 1; i++)
  {
    if (arr[i] > arr[i + 1])
    {
      swap(arr[i], arr[i + 1]);
      didSwap = 1;
    }
  }

  if (didSwap == 0)
    return;

  bubbleSort(arr, n - 1);
}

int main()
{

  // int arr[] = {1321, 12, 12, 1, 3, 5};
  // int n = 6;

  int n;
  cin >> n;

  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << "Before Sorting:" << endl;
  for (int i = 0; i < n; i++)
    cout << arr[i] << "\t";
  cout << endl;
  bubbleSort(arr, n);

  cout << "After Sorting:" << endl;
  for (int i = 0; i < n; i++)
    cout << arr[i] << "\t";
  cout << endl;
}