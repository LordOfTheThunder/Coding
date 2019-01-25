#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <iterator>
#include <cassert>
using namespace std;

/*
Company: Google
Question: Given the root to a binary tree, implement serialize(root), which serializes the tree into a string, and deserialize(s), which deserializes the string back into the tree.
Example: For example, given the following Node class

class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
The following test should pass:

node = Node('root', Node('left', Node('left.left')), Node('right'))
assert deserialize(serialize(node)).left.left.val == 'left.left'
*/

struct node {
	int value;
	node* left;
	node* right;
};

/*
Solution:
	Complexity: N - worst case
	Details:
		Serialization:
			serialize pre order recursively
		Deserialization:
			function object with data to return new tree. We use function object for easier iterations over data string
			Iterations, just like serialization, are also pre order
*/

string treeSerialize(node* head) {
	if (head == NULL) {
		return "None";
	}
	stringstream s;
	s << head->value;
	return s.str() + " " + treeSerialize(head->left) + " " + treeSerialize(head->right);
}

class buildTreeFromInput {
	vector<string> data;
public:
	node * head;
	buildTreeFromInput(vector<string> data) {
		this->data = data;
		this->head = buildTreeFromInputAux(this->data);
	}
	node* buildTreeFromInputAux(vector<string>& data) {
		if (data[0] == "None") {
			data.erase(data.begin());
			return NULL;
		}
		node* head = (node*)malloc(sizeof(node));
		head->value = stoi(data[0]);
		data.erase(data.begin());
		head->left = buildTreeFromInputAux(data);
		head->right = buildTreeFromInputAux(data);

		return head;
	}
};

node* treeDeserialize(string serialization) {
	istringstream iss(serialization);
	vector<string> results((istream_iterator<string>(iss)), istream_iterator<string>());
	buildTreeFromInput b(results);
	return b.head;
}

int main() {
	node* head = (node*)malloc(sizeof(node));
	head->value = 1;
	head->left = (node*)malloc(sizeof(node));
	head->left->value = 2;
	head->right = (node*)malloc(sizeof(node));;
	head->right->value = 5;
	head->left->left = (node*)malloc(sizeof(node));;
	head->left->left->value = 3;
	head->left->right = (node*)malloc(sizeof(node));;
	head->left->right->value = 4;
	head->left->left->left = NULL;
	head->left->left->right = NULL;
	head->left->right->left = NULL;
	head->left->right->right = NULL;
	head->right->left = NULL;
	head->right->right = NULL;
	cout << treeSerialize(head) << endl;
	node* new_head = treeDeserialize(treeSerialize(head));
	assert(new_head->value == head->value);
	assert(new_head->right->value == head->right->value);
	assert(new_head->left->value == head->left->value);
	assert(new_head->left->left->value == head->left->left->value);
	assert(new_head->left->right->value == head->left->right->value);
}