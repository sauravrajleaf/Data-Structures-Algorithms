/*
************************************************************************************************************************************************************************************
<Title>
2 Pointers
************************************************************************************************************************************************************************************
<Introduction>
1.Fixed Window: Given an array arr[] and an integer K, the task is to calculate the sum of all subarrays of size K.
2 variable window - https://leetcode.com/problems/longest-substring-without-repeating-characters/description/


Given a sorted array A
The Sliding Window Technique is a problem-solving technique that is used to

1.Running Average: Use a sliding window to efficiently calculate the average of a fixed-size window as new elements arrive in a stream of data.

2.Formulating Adjacent Pairs: Sliding windows are useful when you need to process adjacent pairs of elements in an ordered data structure, allowing you to easily access and operate on neighboring elements.

3.Target Value Identification: When you want to find a specific target value or combination of values in an array, a sliding window can help by adjusting the window size and efficiently searching for the desired value or subarrays that meet specific criteria.

4.Longest/Shortest/Most Optimal Sequence: Sliding windows are handy when you need to find the longest, shortest, or most optimal sequence that satisfies a given condition in a collection. By sliding a window through the collection and tracking relevant information within it, you can identify the desired sequence more efficiently than scanning the entire collection.

The main idea behind the sliding window technique is to convert two nested loops into a single loop. Usually, the technique helps us to reduce the time complexity from O(n²) or O(n³) to O(n).
This is done by maintaining a sliding window, which is a subarray of the original array that is of a fixed size. The algorithm then iterates over the original array, updating the sliding window as it goes. This allows the algorithm to keep track of a contiguous sequence of elements in the original array, without having to iterate over the entire array multiple times.

https://leetcode.com/discuss/interview-question/3722472/mastering-sliding-window-technique-a-comprehensive-guide
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

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    // Input array
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int i = 0, j = 0; // Window indices windows size = j-i+1
    int sum = 0; // Current window sum

    while (j < n)
    {
        if (j - i + 1 < k)
        {
            // Expand the window by adding element at index j to the sum
            sum += v[j];
            j++;
        }
        else
        {
            // Window size is now equal to the desired window size
            // Calculate the answer for the window
            sum += v[j];
            cout << sum << endl;

            // Move the window by incrementing indices i and j
            sum -= v[i];
            i++, j++;
        }
    }
}

// //Input
// 6 3
// 0 1 1 1 1 0

// //Output
// 2
// 3
// 3
// 2
