#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

/*
Company:	Google
Question:	Given a list of numbers and a number k, return whether any two numbers from the list add up to k.
Example:	For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
*/

/*
Solution:
	Complexity: NlogN - worst case
	Details:	Sort the array and then iterate with two pointers till you find the sum
	Optimization:
		1. use iterators to save run time instead of using [] operator
		2. use temp variables to minimize amount of dereferences
*/

bool twoNumsSumUpToK(vector<int> arr, int k) {
	std::sort(arr.begin(), arr.end());
	vector<int>::iterator it = arr.begin();
	vector<int>::reverse_iterator rev_it = arr.rbegin();
	int temp1 = *it, temp2 = *rev_it;
	while (temp1 != temp2) {
		if (temp1 + temp2 == k) {
			return true;
		}
		else if (temp1 + temp2 > k) {
			++rev_it;
		}
		else {
			++it;
		}
		temp1 = *it;
		temp2 = *rev_it;
	}
	return false;
}

/*
	Solution:
	Complexity: N - Average case
	Details:	Use a hash
	Optimization:
		1. use iterators to save run time instead of using [] operator
		2. use temp variables to minimize amount of dereferences
*/
bool twoNumsSumUpToK_better(vector<int> arr, int k) {
	unordered_set<int> s;
	for (vector<int>::iterator it = arr.begin(); it != arr.end(); ++it) {
		int deref_tmp = *it;
		int temp = k - deref_tmp;
		if (s.find(temp) != s.end()) {
			return true;
		}
		s.insert(deref_tmp);
	}
	return false;
}

int main() {
	vector<int> arr = { 10, 15, 3, 7 };
	if (twoNumsSumUpToK_better(arr, 17)) {
		cout << "Success" << endl;
	}
}