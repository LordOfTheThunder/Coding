#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

/*
Company: Google
Question: A unival tree (which stands for "universal value") is a tree where all nodes under it have the same value.
Given the root to a binary tree, count the number of unival subtrees.
Example: For example, the following tree has 5 unival subtrees:

   0
  / \
 1   0
    / \
   1   0
  / \
 1   1
*/

/*
Solution: Regular recursive search
Complexity: exponential
Optimization: 
*/

struct node {
	int value;
	node* right;
	node* left;
};

class Solution {
public:
	static int getNumOfUniversalSubTrees(node* head) {
		if (head->left == NULL && head->right == NULL) {
			return 1;
		}
		if (head->left == NULL) {
			return getNumOfUniversalSubTrees(head->right);
		}
		if (head->right == NULL) {
			return getNumOfUniversalSubTrees(head->left);
		}
		return (head->right->value == head->left->value) + getNumOfUniversalSubTrees(head->right) + getNumOfUniversalSubTrees(head->left);
	}
};

int main() {
	node* root = (node*)malloc(sizeof(node));
	root->value = 0;
	root->left = (node*)malloc(sizeof(node));
	root->left->value = 1;
	root->left->left = NULL;
	root->left->right = NULL;
	root->right = (node*)malloc(sizeof(node));
	root->right->value = 0;
	root->right->left = (node*)malloc(sizeof(node));
	root->right->left->value = 1;
	root->right->left->left = (node*)malloc(sizeof(node));
	root->right->left->left->value = 1;
	root->right->left->left->left = NULL;
	root->right->left->left->right = NULL;
	root->right->left->right = (node*)malloc(sizeof(node));
	root->right->left->right->value = 1;
	root->right->left->right->left = NULL;
	root->right->left->right->right = NULL;
	root->right->right = (node*)malloc(sizeof(node));
	root->right->right->value = 0;
	root->right->right->left = NULL;
	root->right->right->right = NULL;
	assert(Solution::getNumOfUniversalSubTrees(root) == 5);
	root->right->left->left->value = 0;
	assert(Solution::getNumOfUniversalSubTrees(root) == 4);
}