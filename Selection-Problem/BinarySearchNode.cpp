#include "BinarySearchNode.h"


//ctor with 3 parameters of BinarySearchNode
BinarySearchNode::BinarySearchNode(Person* _person, BinarySearchNode* _left, BinarySearchNode* _right){

	person = _person;
	left = _left;
	right = _right;
}

//dtor of BinarySearchNode
BinarySearchNode::~BinarySearchNode(){
	
	delete left;
	delete right;

}

//getter of person data member
Person* BinarySearchNode::getPerson()
{
	return person;
}

//setter of person data member
void BinarySearchNode::setPerson(Person* _person){

	person = _person;
}

//getter of left data member
BinarySearchNode* BinarySearchNode::getLeft()
{
	return left;
}

//setter of left data member
void BinarySearchNode::setLeft(BinarySearchNode* _left)
{

	left = _left;

}

//getter of right data member
BinarySearchNode* BinarySearchNode::getRight()
{
	return right;
}

//setter of right data member
void BinarySearchNode::setRight(BinarySearchNode* _right)
{
	right = _right;
}
