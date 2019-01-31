#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>
using namespace std;

/*
Company: Airbnb
Question: Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. Numbers can be 0 or negative.
Example: For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. [5, 1, 1, 5] should return 10, since we pick 5 and 5.
*/

/*
Solution: Recursive solution
Complexity: Exponential with N space
Optimization: 
*/

int largestNonAdjacentSum(vector<int> arr) {
	if (arr.size() == 0) {
		return 0;
	}
	if (arr.size() == 1) {
		return arr[0];
	}
	if (arr.size() == 2) {
		return max(arr[0], arr[1]);
	}
	return max(arr[0] + largestNonAdjacentSum(vector<int>(arr.begin() + 2, arr.end())), 
		largestNonAdjacentSum(vector<int>(arr.begin() + 1, arr.end())));
}

/*
Solution: At every iteration have 3 sums. First sum is the sum including the last number.
		Second sum is the sum excluding the last number and third one is a helper sum
		to help us update incl and excl
Complexity: N - worst case
Optimization:
*/

int largestNonAdjacentSum_improved(vector<int> arr) {
	int sum_incl = arr[0], sum_excl = 0;
	int excl_new = 0;
	for (int i = 1; i < arr.size(); ++i) {
		excl_new = max(sum_incl, sum_excl);
		sum_incl = sum_excl + arr[i];
		sum_excl = excl_new;
	}
	return max(sum_incl, sum_excl);
}

int main() {
	assert(largestNonAdjacentSum({ 2, 4, 6, 2, 5 }) == 13);
	assert(largestNonAdjacentSum({ 5, 1, 1, 5 }) == 10);
	assert(largestNonAdjacentSum({ 18, 20, 18, 1 }) == 36);

	assert(largestNonAdjacentSum_improved({ 2, 4, 6, 2, 5 }) == 13);
	assert(largestNonAdjacentSum_improved({ 5, 1, 1, 5 }) == 10);
	assert(largestNonAdjacentSum_improved({ 18, 20, 18, 1 }) == 36);
}