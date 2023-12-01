/*
************************************************************************************************************************************************************************************
<Title>
Binary Search
************************************************************************************************************************************************************************************
<Introduction>
We can use binary search to improve the time complexity.

The whole idea of binary search is to reduce the search space by half in each 
iteration. We keep two variables low and high, which indicate the 
current search space (i.e. the range of indices where our target element might lie).
************************************************************************************************************************************************************************************
Time Complextiy ->
Time Complexity: O(LogN)
************************************
Average -> O(LogN)
************************************
Best -> O(1) If the element is placed at mid itself
************************************
Worst -> O(LogN) - If the array is not sorted
************************************************************************************************************************************************************************************
Space Complexity -> Auxiliary Space: O(1), If the recursive call stack is considered
then the auxiliary space will be O(logN).
************************************************************************************************************************************************************************************
Problem Link -
https://leetcode.com/problems/binary-search/https://www.codingninjas.com/studio/problems/traffic_6682625?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM
https://leetcode.com/discuss/interview-question/1322500/5-variations-of-Binary-search-(A-Self-Note)
https://www.codingninjas.com/studio/problems/binary-search_972?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

More questions in the attached information sources links
************************************************************************************************************************************************************************************
Constraints :
Expected time complexity :
You must write an algorithm with O(log n) runtime complexity.

Constraints:
1 <= nums.length <= 104
-104 < nums[i], target < 104
All the integers in nums are unique.
nums is sorted in ascending order.

Time limit: 1 second

************************************************************************************************************************************************************************************
<Information Sources>
https://leetcode.com/discuss/interview-question/1322500/5-variations-of-Binary-search-(A-Self-Note)
https://leetcode.com/discuss/study-guide/1233854/a-noobs-guide-to-the-binary-search-algorithm
************************************************************************************************************************************************************************************
*/


// C++ program to implement iterative Binary Search
#include <bits/stdc++.h>
using namespace std;

// An iterative binary search function.
int binarySearch(int arr[], int left, int right, int x)
{
	while (left <= right) {
		int mid = left + (right - left) / 2;//To prevent integer overflow

		// Check if x is present at mid
		if (arr[mid] == x)
			return mid;

		// If x greater than the mid element, ignore left half
    //as all the element before the mid are smaller than the mid
		if (arr[mid] < x)
			left = mid + 1;

		// If x is smaller, ignore right half
		else
			right = mid - 1;
	}

	// If we reach here, then element was not present
	return -1;
}

// Driver code
int main(void)
{
	int arr[] = { 2, 3, 4, 10, 40 };
	int x = 10;
	int n = sizeof(arr) / sizeof(arr[0]);
	int result = binarySearch(arr, 0, n - 1, x);
	(result == -1)
		? cout << "Element is not present in array"
		: cout << "Element is present at index " << result;
	return 0;
}

