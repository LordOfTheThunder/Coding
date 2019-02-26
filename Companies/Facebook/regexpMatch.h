#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include <random>
using namespace std;

/*
Company: Facebook
Question: Implement regular expression matching with the following special characters:
. (period) which matches any single character
* (asterisk) which matches zero or more of the preceding element
That is, implement a function that takes in a string and a valid regular expression and returns whether or not the string matches the regular expression.
Example: For example, given the regular expression "ra." and the string "ray", your function should return true. The same regular expression on the string "raymond" should return false.
Given the regular expression ".*at" and the string "chat", your function should return true. The same regular expression on the string "chats" should return false.
*/

/*
Solution: Traverse and match back from end of word to start
Complexity: O(n)
Optimization: 
*/

bool regexpMatch(string str, string regexp) {
	if (str.size() == 0 && regexp.size() != 0) {
		return false;
	}
	for (int i = str.size() - 1, j = regexp.size() - 1; i >= 0 && j >= 0; --j) {
		if (str[i] == regexp[j] || regexp[j] == '.') {
			--i;
			continue;
		}
		if (regexp[j] == '*') {
			// scan backwards as long as possible
			if (j == 0 || regexp [j - 1] == '*') throw exception("Wrong regexp");
			while (str[i] == regexp[j - 1] || regexp[j - 1] == '.') {
				if (j - 2 >= 0 && regexp[j - 2] == str[i]) {
					// a.*b == acdb
					break;
				}
				if (i == 0 && j - 1 != 0) {
					return false;
				}
				if (i == 0) {
					return true;
				}
				--i;
			}
			continue;
		}
		if (regexp[j] != '*' && regexp[j] != str[i]) {
			return false;
		}
	}
	return true;
}

int main() {
	assert(regexpMatch("cdcdcdb", "a.*b") == false);
	assert(regexpMatch("acdcdcdb", "a.*b") == true);
	assert(regexpMatch("chat", ".*at") == true);
	assert(regexpMatch("ray", "ra.") == true);
	assert(regexpMatch("ray", "ra.y") == false);
	assert(regexpMatch("b", "a*b") == true);
	assert(regexpMatch("b", "b*b") == true);
	assert(regexpMatch("aaaaaaaab", "a*b") == true);
	assert(regexpMatch("aaaabc", "a*b") == false);
	assert(regexpMatch("aaaabc", "a*bc") == true);
	assert(regexpMatch("b", "a*b") == true);
}