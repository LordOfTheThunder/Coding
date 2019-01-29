#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

/*
Company: Google
Question: An XOR linked list is a more memory efficient doubly linked list. Instead of each node holding next and prev fields, it holds a field named both, which is an XOR of the next node and the previous node. Implement an XOR linked list; it has an add(element) which adds the element to the end, and a get(index) which returns the node at index.
Example: No examples given
*/

/*
Solution: Build a class for xor node and a struct for node and calculate next and prev using the other pointer
Complexity: add - O(n) - worst case, get - O(n) - worst case
Optimization: 
*/

class xor_node {
public:
	int value;
	xor_node* both;
};

class xor_node_cl {
	xor_node *head = NULL;

	xor_node* get_next(xor_node* node, xor_node* prev) const {
		return (xor_node*)((uintptr_t)node->both ^ (uintptr_t)prev);
	}

	xor_node* get_prev(xor_node* node, xor_node* next) const {
		return (xor_node*)((uintptr_t)node->both ^ (uintptr_t)next);
	}

	xor_node* get_xor(xor_node* first, xor_node* second) const {
		return (xor_node*)((uintptr_t)first ^ (uintptr_t)second);
	}

public:
	void add(int val) {
		if (head == NULL) {
			this->head = new xor_node;
			head->both = NULL;
			head->value = val;
			return;
		}
		xor_node* prev = NULL;
		xor_node* curr = head;
		while (get_next(curr, prev) != NULL) {
			xor_node* tmp = curr;
			curr = get_next(curr, prev);
			prev = tmp;
		}

		xor_node* new_node = new xor_node;
		new_node->value = val;
		curr->both = get_xor(prev, new_node);
		new_node->both = curr;
	}

	xor_node* get(int index) {
		xor_node* curr = head;
		xor_node* prev = NULL;
		for (int i = 0; i < index; ++i) {
			xor_node* tmp = curr;
			curr = get_next(curr, prev);
			prev = tmp;
			assert(curr != NULL);
		}
		return curr;
	}
};

int main() {
	xor_node_cl xor_list;
	xor_list.add(3);
	xor_list.add(5);
	xor_list.add(8);
	assert(xor_list.get(0)->value == 3);
	assert(xor_list.get(1)->value == 5);
	assert(xor_list.get(2)->value == 8);
}