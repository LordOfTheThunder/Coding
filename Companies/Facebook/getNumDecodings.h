#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

/*
Company: Facebook
Question: Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.
Example: For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.
*/

/*
Solution: Recursive solution by removing from the right side and checking result
Complexity: Exponential
Optimization: 
*/

int getNumDecodings(string msg) {
	if (msg.size() <= 1) {
		return 1;
	}
	int count = 0;
	if (msg.back() > '0')
		count = getNumDecodings(msg.substr(0, msg.size() - 1));
	if (msg[msg.size() - 2] == '1' || (msg[msg.size() - 2] == 2 && msg.back() < '7'))
		count += getNumDecodings(msg.substr(0, msg.size() - 2));
	return count;
}

int main() {
	assert(getNumDecodings("111") == 3);
	assert(getNumDecodings("11") == 2);
	assert(getNumDecodings("250") == 0);
	assert(getNumDecodings("1010") == 1);
}