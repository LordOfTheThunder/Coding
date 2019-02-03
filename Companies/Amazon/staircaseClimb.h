#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include <set>
using namespace std;

/*
Company: Amazon
Question: There exists a staircase with N steps, and you can climb up either 1 or 2 steps at a time. Given N, write a function that returns the number of unique ways you can climb the staircase. The order of the steps matters.
Example: For example, if N is 4, then there are 5 unique ways:
	1, 1, 1, 1
	2, 1, 1
	1, 2, 1
	1, 1, 2
	2, 2
*/

/*
Solution: Standard recursive solution
Complexity: Exponential
Optimization: 
*/

int staircaseClimb(int num) {
	if (num < 0) {
		return 0;
	}
	if (num == 0) {
		return 1;
	}
	return staircaseClimb(num - 1) + staircaseClimb(num - 2);
}

int staircaseClimbFromSet(int num, set<int> steps) {
	if (num < 0) {
		return 0;
	}
	if (num == 0) {
		return 1;
	}
	int sum = 0;
	for (const int& step : steps) {
		sum += staircaseClimbFromSet(num - step, steps);
	}
	return sum;
}

int main() {
	assert(staircaseClimb(4) == 5);
	assert(staircaseClimbFromSet(4, { 1, 2 }) == 5);
}