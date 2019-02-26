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
Company: Amazon
Question: Implement run-length encoding and decoding. You can assume the string to be encoded have no digits and consists solely of alphabetic characters. You can assume the string to be decoded is valid.
Example:  For example, the string "AAAABBBCCDAA" would be encoded as "4A3B2C1D2A".
*/

/*
Solution: Easy...
Complexity: O(n)
Optimization: 
*/

class stringManipulation {
public:
	string encodeString(string str) {
		string res;
		int count = 1;
		char last = str[0];
		for (int i = 1; i < str.size(); ++i) {
			if (str[i] == last) {
				++count;
				continue;
			}
			stringstream s;
			s << count << last;
			count = 1;
			last = str[i];
			res.append(s.str());
		}

		stringstream s;
		s << count << last;
		count = 1;
		last = str[str.size() - 1];
		res.append(s.str());

		return res;
	}

	string decodeString(string str) {
		string res;
		string tmp;
		for (int i = 0; i < str.size(); ++i) {
			while (str[i] <= '9' && str[i] >= '0') {
				tmp += str[i++];
			}
			int curr = std::stoi(tmp);
			tmp = "";
			char curr_char = str[i];
			for (int j = 0; j < curr; ++j) {
				res += curr_char;
			}
		}
		
		return res;
	}
};

int main() {
	stringManipulation s;
	cout << s.encodeString("AABBBBCCCCCCCDDD") << endl;
	cout << s.decodeString("3A2B5C1D") << endl;
}