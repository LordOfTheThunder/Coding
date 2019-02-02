#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

/*
Company: Twitter
Question: Implement an autocomplete system. That is, given a query string s and a set of all possible query strings, return all strings in the set that have s as a prefix.
Example: For example, given the query string de and the set of strings [dog, deer, deal], return [deer, deal].
*/

/*
Solution: preprocess the input into a Trie class which has the words prefixes
		For example:
					o - g
		root -> d /
				  \		e - r
					e /
					  \
					    a - l
		This way we search "de" and then return deer and deal
Complexity: O(n) to build the trie when n is the length of the longest word.
			O(n) to find the word given the longest word is of length n.
			Total complexity O(n)
Optimization: 
*/

// expect to get lower case
int char_to_num(char c) {
	return c - 'a';
}

struct trie_node {
	trie_node* nodes[26];
	trie_node() {
		for (int i = 0; i < 26; ++i) {
			nodes[i] = NULL;
		}
	}
};

class Trie {
	trie_node* root;
	vector<string> findWordsRecursively(string prefix, trie_node* curr) {
		vector<string> res;
		for (int i = 0; i < 26; ++i) {
			if (curr->nodes[i] != NULL) {
				vector<string> curr_res = findWordsRecursively(prefix + string(1, 'a' + i), curr->nodes[i]);
				res.insert(res.end(), curr_res.begin(), curr_res.end());
			}
		}
		if (res.empty()) {
			return { prefix };
		}
		return res;
	}
	void deleteRootRecursively(trie_node* root) {
		for (int i = 0; i < 26; ++i) {
			if (root->nodes[i] != NULL)
				deleteRootRecursively(root->nodes[i]);
		}
		delete root;
	}
public:
	Trie() {
		// init root
		root = new trie_node();
	}
	void insert(string word) {
		// insert word to trie
		trie_node* curr = this->root;
		for (char& c : word) {
			if (curr->nodes[char_to_num(c)] == NULL) {
				curr->nodes[char_to_num(c)] = new trie_node();
			}
			curr = curr->nodes[char_to_num(c)];
		}
	}
	vector<string> find(string prefix) {
		// find all words starting with prefix
		trie_node* curr = this->root;
		for (char& c : prefix) {
			curr = curr->nodes[char_to_num(c)];
			if (curr == NULL) {
				return {};
			}
		}
		return findWordsRecursively(prefix, curr);
	}
	~Trie() {
		deleteRootRecursively(this->root);
	}
};

void printVector(vector<string> v) {
	for (string& s : v) {
		cout << s << endl;
	}
}

int main() {
	Trie t;
	t.insert("dog");
	t.insert("deer");
	t.insert("deal");
	printVector(t.find("de"));
}