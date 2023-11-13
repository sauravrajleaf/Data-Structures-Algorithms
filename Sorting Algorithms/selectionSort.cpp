/*
************************************************************************************************************************************************************************************
<Title>
Iterative Selection Sort using Array
************************************************************************************************************************************************************************************
<Introduction>
Selection sort is a simple and efficient sorting algorithm that works by repeatedly 
selecting the smallest (or largest) element from the unsorted portion of the list and moving 
it to the sorted portion of the list. 
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
Problem Link - https://www.codingninjas.com/studio/problems/selection-sort_624469?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM
Status - Accepted
************************************************************************************************************************************************************************************
Constraints :
0 <= N <= 10^3
0 <= arr[i] <= 10^5
Time Limit: 1 sec
************************************************************************************************************************************************************************************
<Information Sources>
https://www.geeksforgeeks.org/insertion-sort/
***************************************************                                                          *********************************************************************************************************************************
*/

#include <bits/stdc++.h>

using namespace std;


void selectionSort(int arr[],int n) {
    // Write your code here.
    //vector<int>&arr - passing by reference

    //selection sort - in every iteration we take the minimum from the unsorted array and place it at its correct place.


    for(int i=0;i<=n-2;i++) {

        //lets assume the current element at (i) in every iteration is 
        //the smallest element.
        int min_element_idx = i;

        //This loop compares all elements with the next right element and 
        //check if it is smaller 
        //if smaller - the index for the minimum element is updated
        for(int j=i;j<=n-1;j++) {

            if(arr[j] < arr[min_element_idx]) {
                min_element_idx = j;
            }
        }

        //after we have found the right index of the smallest element in the 
        //unsorted array we swap the wrong placed element with the right one
        swap(arr[i],arr[min_element_idx]);
    }

    // return arr;


}

int main()
{
  int arr[] = {10, 24, 1, 2, 0, 12, 200};
  int n = sizeof(arr)/sizeof(arr[0]);

  cout << "Before Sorting:" << endl;
  for (int i = 0; i < 7; i++)
    cout << arr[i] << "\t";
  cout << endl;
  selectionSort(arr,n);

  cout << "After Sorting:" << endl;
  for (int i = 0; i < 7; i++)
    cout << arr[i] << "\t";
  cout << endl;
}

//Input-Output
// Before Sorting:
// 10	24	1	2	0	12	200	
// After Sorting:
// 0	1	2	10	12	24	200	
