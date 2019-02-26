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
Question: Given a singly linked list and an integer k, remove the kth last element from the list. k is guaranteed to be smaller than the length of the list.
Example: 
*/

/*
Solution: First take a pointer and advance it by k+1. Then take a curr to be head->next and prev to be head and advance all three of them till first pointer reaches null. Then remove from list using curr and prev.
Complexity: O(n)
Optimization: 
*/

class node {
public:
	int value;
	node* next;
	node(int value) : value(value), next(NULL) {}
};

ostream& operator<<(ostream& out, const node& n) {
	out << n.value;
	return out;
}

void removeKthLastElementFromList(node* head, int k) {
	if (head == NULL) {
		return;
	}
	node* curr = head;
	for (int i = 0; i <= k; ++i) {
		curr = curr->next;
	}
	node* ret_curr = head->next;
	node* prev = head;
	while (curr != NULL) {
		curr = curr->next;
		ret_curr = ret_curr->next;
		prev = prev->next;
	}
	prev->next = ret_curr->next;
	delete ret_curr;
}

int main() {
	node* head = new node(3);
	head->next = new node(2);
	head->next->next = new node(5);
	head->next->next->next = new node(1);
	head->next->next->next->next = new node(4);
	head->next->next->next->next->next = new node(6);
	removeKthLastElementFromList(head, 3);
	for (node* curr = head; curr != NULL; curr = curr->next) {
		cout << *curr << " ";
	}
}