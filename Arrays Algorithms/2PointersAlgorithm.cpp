/*
************************************************************************************************************************************************************************************
<Title>
2 Pointers
************************************************************************************************************************************************************************************
<Introduction>
Given a sorted array A
Two pointers is another common technique for tracking the elements in a sliding window. This is because two pointers can easily track the start and end of the window.
Both fixed and variable window sliding window problems can use the techniques of hashing, two pointers, and sliding window optimization.
Types of Problems on 2 pointers
1.Running from both ends of an array
2.Slow & Fast Pointers
3.Running from beginning of 2 arrays / Merging 2 arrays
4.Split & Merge of an array / Divide & Conquer
************************************************************************************************************************************************************************************
Time Complextiy ->
Time Complexity: O(N), Only one traversal of the array is needed.
************************************
Average -> O(N)
************************************
Best -> O(N)
************************************
Worst -> O(NLogN) - If the array is not sorted
************************************************************************************************************************************************************************************
Space Complexity -> O(1), No extra space is required.
************************************************************************************************************************************************************************************
Problem Link -
Given a sorted array A (sorted in ascending order), having N integers, find if there exists any pair of elements (A[i], A[j]) such that their sum is equal to X.

https://www.codingninjas.com/studio/problems/longest-subarray-with-sum-k_6682399?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
https://www.codingninjas.com/studio/problems/traffic_6682625?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM
https://www.codingninjas.com/studio/problems/sort-an-array-of-0s-1s-and-2s_892977?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
More questions in the attached information sources links
************************************************************************************************************************************************************************************
Constraints :
Expected time complexity :
The expected time complexity is O(n).


Constraints:


Time limit: 1 second

************************************************************************************************************************************************************************************
<Information Sources>
https://leetcode.com/discuss/interview-question/3722472/mastering-sliding-window-technique-a-comprehensive-guidehttps://www.youtube.com/watch?v=tp8JIuCXBaU&embeds_referring_euri=https%3A%2F%2Ftakeuforward.org%2F&source_ve_path=OTY3MTQ&feature=emb_imp_woyt
https://leetcode.com/discuss/study-guide/1688903/Solved-all-two-pointers-problems-in-100-days
https://www.codingninjas.com/studio/library/what-is-a-two-pointer-technique
************************************************************************************************************************************************************************************
*/

#include <bits/stdc++.h>

using namespace std;

bool pairSumExists(vector<int> arr,int n,int sum) {
  
  int start = 0;

  int end = n-1;

  //Loop till the left pointer and right pointer does not cross each other
  while(start < end) {
    
    if(arr[start] + arr[end] == sum) {
      return true;
    }

    if(arr[start] + arr[end] < sum) {

      // If sum of elements at current
      // pointers is higher than expected, we move towards more right
      start++;
    }else {
       // If sum of elements at current
      // pointers is higher than expected, we move towards more left

      end--;
    }
  }

  return false;
}

int main()
{
  //As the array is already sorted here we don't need to sort it
  vector<int> arr = {1,3,4,6,7,8,9};
  int size = arr.size();

  int sum = 111;//Find this sum exists in the array or not

  bool ans = pairSumExists(arr,size,sum);

  if(ans) cout<<"Sum exists in the array"<<endl;
  else cout<<"Sum does not exists in the array"<<endl;
}