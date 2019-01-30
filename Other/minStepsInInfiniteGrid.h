#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>
using namespace std;

/*
Company: None
Question: Given two integer arrays A and B, where A[i] is x coordinate and B[i] is y coordinate of ith point respectively.
Example: Input : [(0, 0), (1, 1), (1, 2)]
		 Output : 2
*/

/*
Solution: Find minimum distance between two consecutive points
Complexity: N - worst case
Optimization: 
*/

class point {
public:
	int x;
	int y;
	point(int x, int y) : x(x), y(y) {}
};

class Solution {
	static int min_dist_between_points(point p1, point p2) {
		return max(abs(p1.x - p2.x), abs(p1.y - p2.y));
	}
public:
	static int numOfStepsInPointList(vector<point> point_list) {
		int sum = 0;
		for (int i = 0; i < point_list.size() - 1; ++i) {
			sum += min_dist_between_points(point_list[i], point_list[i + 1]);
		}
		return sum;
	}
};

int main() {
	assert(Solution::numOfStepsInPointList({ point(0,0), point(1,1), point(1,2) }) == 2);
}