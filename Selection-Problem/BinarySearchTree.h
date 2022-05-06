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
	bool isEmptyBST();
	void makeEmptyBST();
	void buildBST(vector<Person>& personArr, int& numComp);
	BinarySearchNode* FindInBST(int personId, int& numComp);
	void insertToBST(Person p, int& numComp);
	void deleteFromBST(BinarySearchNode*& currRoot, int personId);
	void searchKey(BinarySearchNode*& curr, int personId, BinarySearchNode*& parent);
	BinarySearchNode* getMinKey(BinarySearchNode* curr);
};