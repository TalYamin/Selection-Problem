#pragma once

#include "Person.h"

class BinarySearchNode {
	
	Person person;
	BinarySearchNode* left;
	BinarySearchNode* right;

public:

	//ctors + dtors
	BinarySearchNode()=default;
	BinarySearchNode(Person _person, BinarySearchNode* _left, BinarySearchNode* _right);
	~BinarySearchNode();

	//getter + setters
	Person getPerson() const;
	void setPerson(Person _person);
	BinarySearchNode* getLeft();
	void setLeft(BinarySearchNode* _left);
	BinarySearchNode* getRight();
	void setRight(BinarySearchNode* _right);

};