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
Question: Implement locking in a binary tree. A binary tree node can be locked or unlocked only if all of its descendants or ancestors are not locked.
Design a binary tree node class with the following methods:
is_locked, which returns whether the node is locked
lock, which attempts to lock the node. If it cannot be locked, then it should return false. Otherwise, it should lock it and return true.
unlock, which unlocks the node. If it cannot be unlocked, then it should return false. Otherwise, it should unlock it and return true.
You may augment the node to add parent pointers or any other property you would like. You may assume the class is used in a single-threaded program, so there is no need for actual locks or mutexes. Each method should run in O(h), where h is the height of the tree.
Example: 
*/

/*
Solution: node with parent, counter for num of children who are locked
Complexity: Each operation runs in O(h) when h is the height of the tree
Optimization: 
*/

class LockableTree {
	LockableTree* right;
	LockableTree* left;
	LockableTree* parent;
	int value;
	int locked_descendants_count;
	bool locked;

	bool descendants_unlocked() {
		return locked_descendants_count == 0;
	}

	bool ancestors_unlocked() {
		LockableTree* curr = parent;
		while (curr != NULL) {
			if (curr->locked) {
				return false;
			}
			curr = curr->parent;
		}
		return true;
	}

	bool can_be_locked() {
		return descendants_unlocked() && ancestors_unlocked();
	}

public:
	LockableTree() {
		parent = NULL;
		right = NULL;
		left = NULL;
	}

	bool lock_node() {
		if (!can_be_locked()) {
			return false;
		}
		locked = true;

		LockableTree* curr = parent;
		while (curr != NULL) {
			++curr->locked_descendants_count;
			curr = curr->parent;
		}

		return true;
	}
	
	bool unlock_node() {
		if (!can_be_locked()) {
			return false;
		}
		locked = false;

		LockableTree* curr = parent;
		while (curr != NULL) {
			--curr->locked_descendants_count;
			curr = curr->parent;
		}

		return true;
	}

};

int main() {
}