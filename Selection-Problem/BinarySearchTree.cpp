#include "BinarySearchTree.h"

BinarySearchTree::~BinarySearchTree()
{
}

BinarySearchNode* BinarySearchTree::FindInBST(int personId){

	BinarySearchNode* currNode = root;
	while (currNode != nullptr){
		if (personId == (currNode->getPerson().getPersonId())){
			return currNode;
		}
		else if (personId < (currNode->getPerson().getPersonId())) {
			currNode = currNode->getLeft();
		}
		else {
			currNode = currNode->getRight();
		}
	}

	return nullptr;
}

void BinarySearchTree::insertToBST(Person p){

	if (FindInBST(p.getPersonId()) != nullptr){
		//Handle Error
	}
	BinarySearchNode* temp = root;
	BinarySearchNode* parent = nullptr;
	BinarySearchNode* newNode;

	while (temp != nullptr) {
		parent = temp;
		if (p.getPersonId() < temp->getPerson().getPersonId()){
			temp = temp->getLeft();
		}
		else {
			temp = temp->getRight();
		}
	}
	newNode = new BinarySearchNode(p, nullptr, nullptr);
	if (parent==nullptr){
		root = newNode;
	}
	else if (p.getPersonId() < parent->getPerson().getPersonId()) {
		parent->setLeft(newNode);
	}
	else {
		parent->setRight(newNode);
	}
}

void BinarySearchTree::deleteFromBST(int personId)
{
}
