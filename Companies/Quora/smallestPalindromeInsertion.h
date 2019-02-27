#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include <random>
using namespace std;

/*
Company: Quora
Question: Given a string, find the palindrome that can be made by inserting the fewest number of characters as possible anywhere in the word. If there is more than one palindrome of minimum length that can be made, return the lexicographically earliest one (the first one alphabetically).
Example: For example, given the string "race", you should return "ecarace", since we can add three letters to it (which is the smallest amount to make a palindrome). There are seven other palindromes that can be made from "race" by adding three letters, but "ecarace" comes first alphabetically.

As another example, given the string "google", you should return "elgoogle".
*/

/*
Solution: Find LCS and the result is size of array - LCS
Complexity: O(n^2) time and space
Optimization: 
*/

int smallestPalindromeInsertion(string str) {
	int n = str.size();
	int **dp = (int**)malloc(sizeof(int*) * (n + 1));
	for (int i = 0; i < n + 1; ++i) {
		dp[i] = (int*)malloc(sizeof(int) * (n + 1));
	}
	string str_reversed(str);
	std::reverse(str_reversed.begin(), str_reversed.end());
	// This is the solution for LCS
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (i == 0 || j == 0) {
				dp[i][j] = 0;
			}
			else if (str[i - 1] == str_reversed[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return n - dp[n][n];
}


int main() {
	cout << smallestPalindromeInsertion("google") << endl;
}