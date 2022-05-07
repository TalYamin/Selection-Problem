#pragma once

#include "BinarySearchNode.h"
#include <vector>
#include<iostream> //for test


using namespace std; //for test

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
	void insertToBST(Person* p, int& numComp);
	void deleteFromBST(BinarySearchNode*& currRoot, int personId);
	void searchKey(BinarySearchNode*& curr, int personId, BinarySearchNode*& parent);
	BinarySearchNode* getMinKey(BinarySearchNode* curr);
	BinarySearchNode* inOrderByIndexWrapper(int k);
	int inOrderByIndex(BinarySearchNode* currRoot, BinarySearchNode** kNode, int k, int counter);
	void HandleError();
};