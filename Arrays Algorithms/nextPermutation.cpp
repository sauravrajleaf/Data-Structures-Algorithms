/*
************************************************************************************************************************************************************************************
<Title>
Next Greater Permutation
************************************************************************************************************************************************************************************
<Introduction>

************************************************************************************************************************************************************************************
Time Complextiy ->

************************************
Average -> O(3N) N- is the size of the array.
************************************
Best -> O(3N) N- is the size of the array.
************************************
Worst -> O(3N) N- is the size of the array.
************************************************************************************************************************************************************************************
Space Complexity ->
************************************************************************************************************************************************************************************
Problem Link -
Status - Accepted
************************************************************************************************************************************************************************************
Constraints :
************************************************************************************************************************************************************************************
<Information Sources>
https://takeuforward.org/data-structure/quick-sort-algorithm/
https://www.geeksforgeeks.org/quick-sort/
************************************************************************************************************************************************************************************
*/


// Without STL
//Time Complexity - O(3N) N- is the size of the array. 
//Finding the break point - O(N)
//Finding the next greater element - O(N)
//Reversing the array - O(N)
//Space Complexity - O(1)

#include<bits/stdc++.h>


using namespace std;


vector<int> nextGreaterPermutation(vector<int> &A) {
    // Write your code here.
   int ind = -1;
   int n = A.size();

    //The first loops keep going left from the 2nd last element at every step comparing with the next
    //the moment we find the current element to be lower than the next 
    //we break and we place a pointer at that element
   for(int i=n-2; i>=0; i--) {
       if(A[i] < A[i+1]) {
           ind = i;
           break;
       }
   }

   //If no such element is found which is lower than next one
   //then the whole array is already sorted in descending order
   //which is the last value of the next_permuation
   //In this case just reverse the array so that the array gets sorted in the ascending order
   if(ind == -1) {
       reverse(A.begin(), A.end());
       return A;
   }

    //The last loop is to swap the element pointing at ind with the
    //immediate higher element 
    //so we run a loop from the last element to element before the pointer
    //the intention of running the loop from the last position here is because
    //of the lexicographic nature
    //if you analyse from the last element, it keeps increasing until a lower element(ind)
    //thats how all the next permutations are created
    //so by going left from the last element we will be seeing all the values in a sorted order(ascending)
    for(int i=n-1; i>ind; i--) {
        if(A[i] > A[ind]) {
            swap(A[i], A[ind]);
            break;
        }
    }

    //the last step is to reverse the part of the array greater than ind
    //this is done because now as we have already found the higher element 
    //at ind -> this means we already have the prefix ready for the next permutation
    //prefix - range [0,ind]
    //for the left range we should minimise it as much as possible
    //for that we reverse the array from range ind>=n
    //and again we reverse it because so by going left from the last element we will be seeing all the values in a sorted order(ascending)
    //so by reversing we get the sorted order in asending

    reverse(A.begin()+ind+1,A.end());

    return A;
}

int main() {
  vector<int> arr= {1,2,3,4};

 nextGreaterPermutation(arr);

  cout<<"Next Greater Permutation is\t";

  for(int i=0; i< arr.size(); i++) {
    cout<<arr[i];
  }

  cout<<endl;
  
}


//Output
//Next Greater Permutation is	1243




// with STL
// // vector<int> nextGreaterPermutation(vector<int> &A) {
// //     // Write your code here.
// //     next_permutation(A.begin(),A.end());
// //     return A;
    
// // }