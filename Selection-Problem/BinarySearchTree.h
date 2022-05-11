#pragma once

#include "BinarySearchNode.h"
#include "Utils.h"
#include <vector>


class BinarySearchTree {

	//data members
	BinarySearchNode* root = nullptr;

public:

	//ctors + dtors
	BinarySearchTree()=default;
	~BinarySearchTree();

	//public functions
	void buildBST(vector<Person>& personArr, int& numComp);
	BinarySearchNode* inOrderByIndexWrapper(int k, int& numComp);

	//private functions
private:
	bool isEmptyBST();
	void makeEmptyBST();
	BinarySearchNode* FindInBST(int personId, int& numComp);
	void insertToBST(Person* p, int& numComp);
	void deleteFromBST(BinarySearchNode*& currRoot, int personId, int& numComp);
	void searchKey(BinarySearchNode*& curr, int personId, BinarySearchNode*& parent, int& numComp);
	BinarySearchNode* getMinKey(BinarySearchNode* curr);
	int inOrderByIndex(BinarySearchNode* currRoot, BinarySearchNode** kNode, int k, int counter, int& numComp);
};