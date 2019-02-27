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
Company: Dropbox
Question: Given the root to a binary search tree, find the second largest node in the tree.
Example: 
*/

/*
Solution: Few possible ways to find second largest depending on rightmost node
Complexity: O(logn) worst case
Optimization: 
*/

class Tree {
public:
	int value;
	Tree* right;
	Tree* left;
	Tree(int value) : value(value), right(NULL), left(NULL) {}
};

int findSecondLargestFromSearchTree(Tree* head) {
	Tree* curr = head;
	// get rightmost node in the tree which is the largest
	Tree* prev = NULL;
	while (curr->right != NULL) {
		prev = curr;
		curr = curr->right;
	}

	if (prev == NULL) {
		// tree with just 2 nodes, the other one is on the left.
		return curr->left->value;
	}

	if (curr->left == NULL) {
		// no left subtree to rightmost. Return parent
		return prev->value;
	}
	curr = curr->left;
	while (curr->right != NULL) {
		curr = curr->right;
	}
	return curr->value;
}

int main() {
	Tree* head = new Tree(5);
	head->left = new Tree(3);
	assert(findSecondLargestFromSearchTree(head) == 3);
	head->right = new Tree(7);
	assert(findSecondLargestFromSearchTree(head) == 5);
	head->right->left = new Tree(6);
	assert(findSecondLargestFromSearchTree(head) == 6);
	head->right->right = new Tree(9);
	assert(findSecondLargestFromSearchTree(head) == 7);
}