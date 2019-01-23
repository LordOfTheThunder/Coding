#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>
using namespace std;

/*
	Info: Get a line of numbers from input separated by spaces, split it by space and return as vector of ints
*/
vector<int> inputToIntVector() {
	string data;
	getline(cin, data);

	istringstream iss(data);
	vector<string> results((istream_iterator<string>(iss)), istream_iterator<string>());
	vector<int> int_res;
	transform(results.begin(), results.end(), back_inserter(int_res),
		[](const string& str) { return stoi(str); });
	return int_res;
}