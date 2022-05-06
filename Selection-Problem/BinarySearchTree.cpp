#include "BinarySearchTree.h"

BinarySearchTree::~BinarySearchTree()
{
}

BinarySearchNode* BinarySearchTree::FindInBST(int personId) {

	BinarySearchNode* currNode = root;
	while (currNode != nullptr) {
		if (personId == (currNode->getPerson().getPersonId())) {
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

void BinarySearchTree::insertToBST(Person p) {

	if (FindInBST(p.getPersonId()) != nullptr) {
		//Handle Error
	}
	BinarySearchNode* temp = root;
	BinarySearchNode* parent = nullptr;
	BinarySearchNode* newNode;

	while (temp != nullptr) {
		parent = temp;
		if (p.getPersonId() < temp->getPerson().getPersonId()) {
			temp = temp->getLeft();
		}
		else {
			temp = temp->getRight();
		}
	}
	newNode = new BinarySearchNode(p, nullptr, nullptr);
	if (parent == nullptr) {
		root = newNode;
	}
	else if (p.getPersonId() < parent->getPerson().getPersonId()) {
		parent->setLeft(newNode);
	}
	else {
		parent->setRight(newNode);
	}
}

void BinarySearchTree::deleteFromBST(BinarySearchNode*& currRoot, int personId) {

	BinarySearchNode* parent = nullptr;
	BinarySearchNode* curr = currRoot;

	searchKey(curr, personId, parent);

	if (curr == nullptr) {
		return;
	}

	if (curr->getLeft() == nullptr && curr->getRight() == nullptr) {
		if (curr != currRoot) {
			if (parent->getLeft() == curr) {
				parent->setLeft(nullptr);
			}
			else {
				parent->setRight(nullptr);
			}
		}
		else {
			currRoot = nullptr;
		}

		delete curr;
	}


	else if (curr->getLeft() != nullptr && curr->getRight() != nullptr) {
		BinarySearchNode* successor = getMinKey(curr->getRight());
		Person p = successor->getPerson();
		deleteFromBST(currRoot, successor->getPerson().getPersonId());
		curr->setPerson(p);
	}

	else {
		BinarySearchNode* child;
		if (curr->getLeft() != nullptr) {
			child = curr->getLeft();
		}
		else {
			child = curr->getRight();
		}
		if (curr != currRoot) {
			if (curr == parent->getLeft()){
				parent->setLeft(child);
			}
			else {
				parent->setRight(child);
			}
		}
		else {
			currRoot = child;
		}
		delete curr;
	}

}


void BinarySearchTree::searchKey(BinarySearchNode*& curr, int personId, BinarySearchNode*& parent) {

	while (curr != nullptr && curr->getPerson().getPersonId() != personId) {
		parent = curr;

		if (personId < curr->getPerson().getPersonId()) {
			curr = curr->getLeft();
		}
		else {
			curr = curr->getRight();
		}
	}
}

BinarySearchNode* BinarySearchTree::getMinKey(BinarySearchNode* curr) {
	while (curr->getLeft() != nullptr) {
		curr = curr->getLeft();
	}

	return curr;
}
