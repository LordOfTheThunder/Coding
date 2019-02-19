#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include <random>
using namespace std;

/*
Company: Twitter
Question: You run an e-commerce website and want to record the last N order ids in a log. Implement a data structure to accomplish this, with the following API:
	record(order_id): adds the order_id to the log
	get_last(i): gets the ith last element from the log. i is guaranteed to be smaller than or equal to N.
You should be as efficient with time and space as possible.
Example: 
*/

/*
Solution: Class for last N orders containing an array, its size and curr index
Complexity: O(1) time and O(n) space worst case
Optimization: 
*/

class lastNOrders {
	int curr_idx;
	int *orders;
	int size;
public:
	lastNOrders(int N) : curr_idx(0) {
		orders = new int[N];
		size = N;
	}
	~lastNOrders() {
		delete[] orders;
	}
	void record(int order_id) {
		orders[curr_idx % size] = order_id;
		curr_idx = (curr_idx + 1) % size;
	}
	int get_last(int i) const {
		return orders[(curr_idx + size - i - 1) % size];
	}
};

int main() {
	lastNOrders lno(4);
	lno.record(35);
	lno.record(27);
	lno.record(41);
	lno.record(16);
	assert(lno.get_last(2) == 27);
	assert(lno.get_last(1) == 41);
	lno.record(91);
	assert(lno.get_last(0) == 91);
	assert(lno.get_last(1) == 16);
}