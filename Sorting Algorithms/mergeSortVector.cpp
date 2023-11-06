// Merge sort using array

/*
************************************************************************************************************************************************************************************
<Title>
Merge sort using vector
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

void merge(vector<int> &arr, int low, int mid, int high)
{
  vector<int> temp;    // temporary array
  int left = low;      // starting index of left half of arr
  int right = mid + 1; // starting index of right half of arr

  // storing elements in the temporary array in a sorted manner//

  while (left <= mid && right <= high)
  {
    if (arr[left] <= arr[right])
    {
      temp.push_back(arr[left]);
      left++;
    }
    else
    {
      temp.push_back(arr[right]);
      right++;
    }
  }

  // if elements on the left half are still left //

  while (left <= mid)
  {
    temp.push_back(arr[left]);
    left++;
  }

  //  if elements on the right half are still left //
  while (right <= high)
  {
    temp.push_back(arr[right]);
    right++;
  }

  // transfering all elements from temporary to arr //
  for (int i = low; i <= high; i++)
  {
    arr[i] = temp[i - low];
  }
}

void mergeSort(vector<int> &arr, int low, int high)
{
  if (low >= high)
    return;
  int mid = (low + high) / 2;
  mergeSort(arr, low, mid);      // left half
  mergeSort(arr, mid + 1, high); // right half
  merge(arr, low, mid, high);    // merging sorted halves
}

int main()
{

  vector<int> arr = {9, 4, 7, 6, 3, 1, 5};
  int n = 7;

  cout << "Before Sorting Array: " << endl;
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
  mergeSort(arr, 0, n - 1);
  cout << "After Sorting Array: " << endl;
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}