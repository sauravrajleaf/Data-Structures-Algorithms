/*
************************************************************************************************************************************************************************************
<Title>
Largest Sum Contiguous Subarray (Kadane’s Algorithm)
************************************************************************************************************************************************************************************
<Introduction>
Given an array arr[] of size N. The task is to find the sum of the contiguous subarray within a arr[] with the largest sum.

The idea of Kadane’s algorithm is to maintain a variable max_ending_here that stores the maximum sum 
contiguous subarray ending at current index and a variable max_so_far stores the maximum sum of 
contiguous subarray found so far, Everytime there is a positive-sum value in max_ending_here 
compare it with max_so_far and update max_so_far if it is greater than max_so_far.

Everytime the current maximum sum goes negative the current sum is reset to 0.
************************************************************************************************************************************************************************************
Time Complextiy ->
************************************
Average -> O(N)
************************************
Best -> O(N)
************************************
Worst -> O(N)
************************************************************************************************************************************************************************************
Space Complexity -> O(1)
************************************************************************************************************************************************************************************
Problem Link - https://leetcode.com/problems/maximum-subarray/
Status - Accepted
************************************************************************************************************************************************************************************
Constraints :
************************************************************************************************************************************************************************************
<Information Sources>
https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
https://www.codingninjas.com/studio/problems/maximum-subarray-sum_630526?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM
************************************************************************************************************************************************************************************
*/


//Implementation of Kadane's Algorithm
//Time Complexity - O(N)
//Space Complexity - O(1)

#include <bits/stdc++.h>

using namespace std;

long long maxSubarraySum(vector<int> arr, int n)
{
    // Write your code here.
    long long sum = 0;
    long long max_sum = 0;

    for(auto it: arr) {
        //summing all the current element
        sum += it;

        //at each step keep updating the max sum value
        max_sum = max(max_sum,sum);

        //if the sum at current value goes lesser than 0 
        if(sum < 0) sum = 0 ;

    }
    return max_sum;
}

int main() {
  int n;cin>>n;
  vector<int> arr(n);

  for(int i=0; i<n; i++) cin>>arr[i];

  // int size =  arr.size();

  long long ans = maxSubarraySum(arr,n);

  cout<<"Maximum sum among all the subarrays is\t"<<ans<<endl;
}

// //Input 
// 15
// -7 -8 -16 -4 -8 -5 -7 -11 -10 -12 -4 -6 -4 -16 -10 

// //Output
// Maximum sum among all the subarrays is	0


// //Input 
// 10
// 18 -6 -6 -5 7 10 16 -6 -2 0 

// //Output
// Maximum sum among all the subarrays is	34
