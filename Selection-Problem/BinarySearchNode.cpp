#include "BinarySearchNode.h"

BinarySearchNode::BinarySearchNode(Person* _person, BinarySearchNode* _left, BinarySearchNode* _right){

	person = _person;
	left = _left;
	right = _right;
}

BinarySearchNode::~BinarySearchNode(){

}

Person* BinarySearchNode::getPerson()
{
	return person;
}

void BinarySearchNode::setPerson(Person* _person){

	person = _person;
}

BinarySearchNode* BinarySearchNode::getLeft()
{
	return left;
}

void BinarySearchNode::setLeft(BinarySearchNode* _left)
{

	left = _left;

}

BinarySearchNode* BinarySearchNode::getRight()
{
	return right;
}

void BinarySearchNode::setRight(BinarySearchNode* _right)
{
	right = _right;
}
