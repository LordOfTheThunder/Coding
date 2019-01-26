#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
Company: Stripe
Question: Given an array of integers, find the first missing positive integer in linear time and constant space. In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.
Example: For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.
*/

/*
Solution: swap elements to create histogram and then check first location at which element at histogram doesn't exist
Complexity: N - worst case

*/

int firstMissingPositive(vector<int> arr) {
	int index = 0;
	while (index < arr.size()) {
		if (arr[index] <= arr.size() && arr[index] > 0) {
			if (arr[index] != index + 1) {
				std::swap(arr[index], arr[arr[index] - 1]);
				continue;
			}
		}
		++index;
	}

	for (int i = 0; i < arr.size(); ++i) {
		if (arr[i] != i + 1) {
			return i + 1;
		}
	}
	return arr.size() + 1;
}


int main() {
	vector<int> arr = { 3, 4, 1, -1 };
	cout << firstMissingPositive(arr) << endl;
	vector<int> arr2 = { 1, 2, 0 };
	cout << firstMissingPositive(arr2) << endl;
	vector<int> arr3 = { 3, 2, 1 };
	cout << firstMissingPositive(arr3) << endl;
}