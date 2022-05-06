#pragma once

#include "BinarySearchNode.h"
#include "Utils.h"
#include <vector>

class BinarySearchTree {

	BinarySearchNode* root = nullptr;

public:

	//ctors + dtors
	BinarySearchTree()=default;
	~BinarySearchTree();

	//public functions
	void buildBST(vector<Person>& personArr);
	BinarySearchNode* FindInBST(int personId);
	void insertToBST(Person p);
	void deleteFromBST(BinarySearchNode*& currRoot, int personId);
	void searchKey(BinarySearchNode*& curr, int personId, BinarySearchNode*& parent);
	BinarySearchNode* getMinKey(BinarySearchNode* curr);
};