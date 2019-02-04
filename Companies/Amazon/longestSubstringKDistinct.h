#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

/*
Company: Amazon
Question: Given an integer k and a string s, find the length of the longest substring that contains at most k distinct characters.
Example: For example, given s = "abcba" and k = 2, the longest substring with k distinct characters is "bcb".
*/

/*
Solution: Travel with 2 pointers across the string. Increase and decrease max and curr counters and update when above the limit
Complexity: N - worst case
Optimization: 
*/

int distinctInHist(char hist[26]) {
	int sum = 0;
	for (int i = 0; i < 26; ++i) {
		sum += hist[i] > 0;
	}
	return sum;
}

int longestSubstringKDistinct(char* str, int k) {
	if (strcmp(str, "") == 0) {
		return 0;
	}
	char hist[26] = { 0 };
	char* first = str;
	hist[*first - 'a'] = 1;
	char* second = str;
	int max = 0, curr = 1;
	while (*second != '\0') {
		if (distinctInHist(hist) > k) {
			max = std::max(max, curr - 1);
			--hist[*first - 'a'];
			++first;
			--curr;
			continue;
		}
		++curr;
		++second;
		++hist[*second - 'a'];
	}
	max = std::max(max, curr - 1);
	return max;
}

int main() {
	assert(longestSubstringKDistinct("abccbaa", 3) == 7);
	assert(longestSubstringKDistinct("abcba", 2) == 3);
	assert(longestSubstringKDistinct("aaab", 1) == 3);
	assert(longestSubstringKDistinct("aaabac", 2) == 5);
}