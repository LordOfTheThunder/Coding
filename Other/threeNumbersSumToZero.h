#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cassert>
using namespace std;

/*
Company: None
Question: Check if 3 numbers exist in array with zero sum
Example: for array [3, 0, -3] the answer is true. For array [3, 1, 2] the answer is false
*/

/*
Solution: Hash with 2 loops
Complexity: N^2 - average case
Optimization:
	1. Using unordered set
*/

bool threeNumbersSumToZero(vector<int> arr) {
	for (int i = 0; i < arr.size() - 1; ++i) {
		unordered_set<int> hash;
		for (int j = i + 1; j < arr.size(); ++j) {
			if (hash.find(-(arr[i] + arr[j])) != hash.end()) {
				return true;
			}
			hash.insert(arr[j]);
		}
	}
	return false;
}


int main() {
	assert(threeNumbersSumToZero({ 3, 0, -3 }) == true);
	assert(threeNumbersSumToZero({ 3, 1, -3 }) == false);
}