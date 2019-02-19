#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include <random>
using namespace std;

/*
Company: Google
Question: Given two singly linked lists that intersect at some point, find the intersecting node. The lists are non-cyclical.
Example: For example, given A = 3 -> 7 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10, return the node with value 8.
*/

/*
Solution: find difference in sizes between lists and start them from the same spot while iterating over both at the same time
Complexity: O(M + N) time
Optimization: 
*/

struct node {
	node* next;
	int value;
};

int find_list_length(node* head) {
	int count = 1;
	while ((head = head->next) != NULL) {
		++count;
	}
	return count;
}

node* find_first_common(node* first, node* second) {
	int first_len = find_list_length(first);
	int second_len = find_list_length(second);
	int diff = abs(first_len - second_len);
	node* tmp = NULL;
	if (first_len < second_len) {
		tmp = first;
		first = second;
		second = first;
	}
	for (int i = 0; i < diff; ++i) {
		first = first->next;
	}
	while (first != NULL) {
		if (first == second) {
			return first;
		}
		first = first->next;
		second = second->next;
	}
	return NULL;
}

int main() {
	node* first = (node*)malloc(sizeof(node*));
	first->value = 3;
	first->next = (node*)malloc(sizeof(node*));
	first->next->value = 7;
	first->next->next = (node*)malloc(sizeof(node*));
	first->next->next->value = 8;
	first->next->next->next = (node*)malloc(sizeof(node*));
	first->next->next->next->value = 10;
	first->next->next->next->next = NULL;
	node* second = (node*)malloc(sizeof(node*));
	second->value = 99;
	second->next = (node*)malloc(sizeof(node*));
	second->next->value = 1;
	second->next->next = first->next->next;
	node* res = find_first_common(first, second);
	assert(res->value == 8);
}