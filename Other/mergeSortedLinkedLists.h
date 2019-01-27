#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
Company: None
Question: Merge two sorted linked lists
Example: 1->2->4 and 1->3->4 will return 1->1->2->3->4->4
*/

/*
Solution: Iterate over both list and update pointers whenever an element from the second list is between two elements of the original list
		  When we finish first list add remaining elements from second list to first
Complexity: N - worst case
Optimization: None
*/

struct node {
	node* next;
	int value;
};

node* mergeTwoLists(node* first, node* second) {
	if (first == NULL) {
		return second;
	}
	if (second == NULL) {
		return first;
	}
	node* head;
	if (first->value > second->value) {
		// I want head to be on first list! Swap in case we are on second
		std::swap(first, second);
	}
	head = first;

	node* prev = NULL;
	
	while (first != NULL && second != NULL) {
		prev = first;
		if (first->value < second->value && first->next != NULL && first->next->value < second->value) {
			first = first->next;
			continue;
		}
		node* tmp_second = second->next;
		node* tmp_first = first->next;

		first->next = second;
		second->next = tmp_first;
		first = second;
		second = tmp_second;
	}
	while (second != NULL) {
		prev->next = second;
	}
	return head;
}

int main() {
	node* first = (node*)malloc(sizeof(node));
	first->value = 1;
	first->next = (node*)malloc(sizeof(node));
	first->next->value = 2;
	first->next->next = (node*)malloc(sizeof(node));
	first->next->next->value = 4;
	first->next->next->next = NULL;
	
	node* second = (node*)malloc(sizeof(node));
	second->value = 1;
	second->next = (node*)malloc(sizeof(node));
	second->next->value = 3;
	second->next->next = (node*)malloc(sizeof(node));
	second->next->next->value = 4;
	second->next->next->next = NULL;

	node* head = mergeTwoLists(second, first);
	while (head != NULL) {
		cout << head->value << " ";
		head = head->next;
	}
	cout << endl;
}