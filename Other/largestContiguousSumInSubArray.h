#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

/*
Company: None
Question: Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
Example: Given the array [-2,1,-3,4,-1,2,1,-5,4],
	the contiguous subarray [4,-1,2,1] has the largest sum = 6.
*/

/*
Solution: Kadane’s algorithm - loop for each element and calculate max as long as positive sequence exists
Complexity: N - worst case
Optimization: 
*/

int largestContiguousSumInSubArray(vector<int> arr) {
	int max_so_far = 0;
	int max_ending_here = 0;
	for (int& lm : arr) {
		max_ending_here = max(max_ending_here + lm, 0);
		max_so_far = max(max_so_far, max_ending_here);
	}
	return max_so_far;
}

int main() {
	cout << largestContiguousSumInSubArray({ -2, 1, -3, 4, -1, 2, 1, -5, 4 }) << endl;
}