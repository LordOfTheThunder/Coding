#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>
using namespace std;

struct node {
	node* next;
	int value;
};

/*
Site: Hackerrank
Question: given a positive integer M and a list of integers L, outputs the list element M links away from the end of the list.
*/

/*
Solution:
	Complexity: N - worst case
	Details: First pointer moves m steps forward. Then push bost pointers
*/

int mBeforeLast(node* head, int m) {
	node* m_before_last = head;
	for (int i = 0; i < m; ++i) {
		head = head->next;
		if (head == NULL) {
			return -1;
		}
	}
	while (head != NULL) {
		head = head->next;
		m_before_last = m_before_last->next;
	}
	return m_before_last->value;
}

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

/*
Testing:
	Get data from input and give an answer according to it
*/

int main() {
	string str_before_last;
	getline(cin, str_before_last);
	int num_before_last = stoi(str_before_last);
	vector<int> res = inputToIntVector();
	node* head;
	node* Node = (node*)malloc(sizeof(node));
	head = Node;
	Node->value = res[0];
	for (auto it = res.begin() + 1; it != res.end(); ++it) {
		Node->next = (node*)malloc(sizeof(node));
		Node->next->value = *it;
		Node = Node->next;
	}
	Node->next = NULL;
	cout << mBeforeLast(head, num_before_last);
}