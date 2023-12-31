/*
************************************************************************************************************************************************************************************
<Title>
Merge sort using array
************************************************************************************************************************************************************************************
<Introduction>

************************************************************************************************************************************************************************************
Time Complextiy ->

************************************
Average -> O(N*logN),
************************************
Best -> O(N*logN),
************************************
Worst -> O(N*LogN)
************************************************************************************************************************************************************************************
Space Complexity -> O(1)
************************************************************************************************************************************************************************************
Problem Link - https://www.codingninjas.com/studio/problems/merge-sort_5846?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM
Status - Accepted
************************************************************************************************************************************************************************************
Constraints :
1 <= N <= 10^3
0 <= ARR[i] <= 10^9
************************************************************************************************************************************************************************************
<Information Sources>

************************************************************************************************************************************************************************************
*/

#include <bits/stdc++.h>

using namespace std;

void merge(int arr[], int low, int mid, int high)
{
  int temp[500];
  int left = low;
  int right = mid + 1;
  int idx = low;

  while (left <= mid && right <= high)
  {
    if (arr[left] <= arr[right])
    {
      temp[idx] = arr[left];
      left++;
    }
    else
    {
      temp[idx] = arr[right];
      right++;
    }
    idx++;
  }

  while (left <= mid)
  {
    temp[idx] = arr[left];
    left++;
    idx++;
  }

  while (right <= high)
  {
    temp[idx] = arr[right];
    right++;
    idx++;
  }

  // Copy merged elements back to the original array
  for (int i = low; i <= high; i++)
  {
    arr[i] = temp[i];
  }
}

void mergeSort(int arr[], int low, int high)
{

  // Base Case
  if (low >= high)
    return;
  int mid = (low + high) / 2;
  mergeSort(arr, low, mid);
  mergeSort(arr, mid + 1, high);
  merge(arr, low, mid, high);
}

int main()
{
  int n;
  cin >> n;

  int arr[1001];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  mergeSort(arr, 0, n - 1);

  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << "\t";
  }
  int size = sizeof(arr) / sizeof(arr[0]);
  cout << endl;
}