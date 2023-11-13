/*
************************************************************************************************************************************************************************************
<Title>
Sort an array of 0s, 1s and 2s | Dutch National Flag problem
************************************************************************************************************************************************************************************
<Introduction>
Given an array A[] consisting of only 0s, 1s, and 2s. The task is to write a function that sorts the given array. The functions should put all 0s first, then all 1s and all 2s in last.
************************************************************************************************************************************************************************************
Time Complextiy ->
Time Complexity: O(N), Only one traversal of the array is needed.
************************************
Average -> O(N)
************************************
Best -> O(N)
************************************
Worst -> O(N)
************************************************************************************************************************************************************************************
Space Complexity -> O(1), No extra space is required.
************************************************************************************************************************************************************************************
Problem Link - https://www.codingninjas.com/studio/problems/sort-an-array-of-0s-1s-and-2s_892977?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
Status - Accepted
************************************************************************************************************************************************************************************
Constraints :
Expected time complexity :
The expected time complexity is O(n).


Constraints:
1 <= 'n' <= 10 ^ 4
0 <= 'arr[i]' <= 2

Time limit: 1 second

************************************************************************************************************************************************************************************
<Information Sources>
https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/
https://www.youtube.com/watch?v=tp8JIuCXBaU&embeds_referring_euri=https%3A%2F%2Ftakeuforward.org%2F&source_ve_path=OTY3MTQ&feature=emb_imp_woyt
************************************************************************************************************************************************************************************
*/

#include <bits/stdc++.h>

using namespace std;

void sortArray(vector<int> &arr, int n)
{
  int low = 0, mid = 0, high = n - 1;

  while (mid <= high)
  {
    if (arr[mid] == 0)
    {
      swap(arr[low], arr[mid]);
      low++;
      mid++;
    }
    else if (arr[mid] == 1)
    {
      // Pivot element
      // All other elements are sorted around the pivot element
      mid++;
    }
    else
    {
      swap(arr[mid], arr[high]);
      high--;
    }
  }
}

int main()
{
  vector<int> arr = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};

  int n = arr.size();
  cout << "Before Sorting\n";

  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << "\t";
  }

  cout << endl;
  sortArray(arr, n);

  cout << "After Sorting\n";
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << "\t";
  }
}

// Input
// 0	1	1	0	1	2	1	2	0	0	0	1

// Output
// 0	0	0	0	0	1	1	1	1	1	2	2
