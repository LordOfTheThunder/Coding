#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
Company: Uber
Question: Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.
Example: For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].
Constrain: Complexity O(n) and no division operator
*/

/*
Solution:
	Complexity: N - worst case
	Details: Build left sum arr, right sum arr, and then just multiply them to get result
	Optimization:
		1. Do sum for right and left in one loop
*/

vector<int> getProductExceptI(vector<int> arr) {
	vector<int> left = { 1 };
	vector<int> right = { 1 };
	int curr_left_sum = 1, curr_right_sum = 1;
	for (int i = 0, j = arr.size() - 1; i < arr.size() - 1; ++i, --j) {
		curr_left_sum *= arr[i];
		curr_right_sum *= arr[j];
		left.push_back(curr_left_sum);
		right.insert(right.begin(), curr_right_sum);
	}
	vector<int> res;
	for (int i = 0; i < arr.size(); ++i) {
		res.push_back(left[i] * right[i]);
	}
	return res;
}