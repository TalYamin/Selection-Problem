#include "BinarySearchTree.h"


/*
Function checks if the binary search tree is empty.
*/
bool BinarySearchTree::isEmptyBST()
{
	if (root == nullptr){
		return true;
	}
	return false;
}

/*
This function make the binary search tree empty.
*/
void BinarySearchTree::makeEmptyBST(){
	root = nullptr;
}

/*
This function receives person array and insert them to binary search tree.
*/
void BinarySearchTree::buildBST(vector<Person>& personArr, int& numComp){

	for (int i = 0; i < personArr.size(); i++){
		insertToBST(&personArr[i],numComp);
	}

}

/*
This function receive perosn id and find if this id exist in the 
binary search tree.
*/
BinarySearchNode* BinarySearchTree::FindInBST(int personId, int& numComp) {

	BinarySearchNode* currNode = root;
	while (currNode != nullptr) {
		if (numComp++, personId == (currNode->getPerson()->getPersonId())) {
			return currNode;
		}
		else if (numComp++, personId < (currNode->getPerson()->getPersonId())) {
			currNode = currNode->getLeft();
		}
		else {
			currNode = currNode->getRight();
		}
	}

	return nullptr;
}


/*
This function receives person pointer and insert it as a
node to binary search tree.
*/
void BinarySearchTree::insertToBST(Person* p, int& numComp) {

	BinarySearchNode* temp = root;
	BinarySearchNode* parent = nullptr;
	BinarySearchNode* newNode;

	while (temp != nullptr) {
		parent = temp;
		if (numComp++, p->getPersonId() < temp->getPerson()->getPersonId()) {
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
	else if (numComp++, p->getPersonId() < parent->getPerson()->getPersonId()) {
		parent->setLeft(newNode);
	}
	else {
		parent->setRight(newNode);
	}
}

/*
This function is used to delete node from binary search tree, according
to person id which recevied. 
*/
void BinarySearchTree::deleteFromBST(BinarySearchNode*& currRoot, int personId, int& numComp) {

	BinarySearchNode* parent = nullptr;
	BinarySearchNode* curr = currRoot;

	searchKey(curr, personId, parent, numComp);

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
		Person* p = successor->getPerson();
		deleteFromBST(currRoot, successor->getPerson()->getPersonId(),numComp);
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

/*
This function receives person id, function search the node which contains 
this key in the binary search tree. In addition, function find the parent 
of this node.
*/
void BinarySearchTree::searchKey(BinarySearchNode*& curr, int personId, BinarySearchNode*& parent, int& numComp) {

	while (curr != nullptr && ++numComp && curr->getPerson()->getPersonId() != personId) {
		parent = curr;

		if (numComp++, personId < curr->getPerson()->getPersonId()) {
			curr = curr->getLeft();
		}
		else {
			curr = curr->getRight();
		}
	}
}

/*
Thi function find the current minimum key under the specific node which
received.
*/
BinarySearchNode* BinarySearchTree::getMinKey(BinarySearchNode* curr) {
	while (curr->getLeft() != nullptr) {
		curr = curr->getLeft();
	}

	return curr;
}


/*
This function is wrapper function to recursive inOrderByIndex() function.
*/
BinarySearchNode* BinarySearchTree::inOrderByIndexWrapper(int k, int& numComp) {

	int counter = 0;
	BinarySearchNode* kNode;
	inOrderByIndex(root, &kNode, k, counter,numComp);
	return kNode;
}

/*
This is recursive function. Function passes on the nodes of
binary search tree, by inorder method. And function stops running when
arrived to relevant index and returns the relevant node.
*/
int BinarySearchTree::inOrderByIndex(BinarySearchNode* currRoot, BinarySearchNode** kNode, int k, int counter, int& numComp)
{

	if (currRoot != nullptr) {
		counter = inOrderByIndex(currRoot->getLeft(), kNode, k, counter,numComp);
		counter = counter + 1;
		if (numComp++, k == counter) {
			*kNode = currRoot;
		}
		counter = inOrderByIndex(currRoot->getRight(), kNode, k, counter,numComp);
	}

	return counter;
}

/*
dtor of BinarySearchTree
*/
BinarySearchTree::~BinarySearchTree() {
	delete root;
}


