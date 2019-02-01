#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

/*
Company: None
Question: Given a non-negative number represented as an array of digits,

add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.
Example: If the vector has [1, 2, 3]

the returned vector should be [1, 2, 4]

as 123 + 1 = 124.
*/

/*
Solution: Trivial solution
Complexity: N - worst case
Optimization: 
*/

vector<int> addOneToNumber(vector<int> arr) {
	int idx = arr.size() - 1;
	while (arr[idx] == 9) {
		arr[idx--] = 0;
		if (idx == -1) {
			break;
		}
	}
	if (idx == -1) {
		arr.push_back(0);
		for (auto& lm : arr) {
			lm = 0;
		}
		arr[0] = 1;
		return arr;
	}
	++arr[idx];
	return arr;
}

void printVector(vector<int> arr) {
	for (auto& lm : arr) {
		cout << lm << " ";
	}
	cout << endl;
}

int main() {
	printVector(addOneToNumber({ 1, 2, 3 }));
	printVector(addOneToNumber({ 1, 2, 9 }));
	printVector(addOneToNumber({ 9, 9, 9 }));
}