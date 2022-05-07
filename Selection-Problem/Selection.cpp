#include "Selection.h"

const Person& randSelection(vector<Person>& personArr, int k, int& numComp)
{
	Person* p;
	int left = 0;
	int right = personArr.size()-1;
	p = select(personArr, left, right, k, numComp);
	return *p;
}


Person* select(vector<Person>& personArr, int left, int right, int k, int& numComp) {

	int randIndex;
	int pivotIndex;
	int leftPart;

	randIndex = left + (rand() % (right - left + 1));
	pivotIndex = partition(personArr, left, right, randIndex, numComp);
	leftPart = pivotIndex - left + 1;
	if (k == leftPart){
		return &personArr[pivotIndex];
	}
	if (k < leftPart) {
		return select(personArr, left, pivotIndex - 1, k, numComp);
	}
	else {
		return select(personArr, pivotIndex + 1, right, k - leftPart, numComp);
	}
}




int partition(vector<Person>& personArr, int left, int right, int randIndex, int& numComp) {

	int pivot = left;
	int nonPivot = right;
	bool nonPivotIsOnRight = true;

	swap(personArr[left], personArr[randIndex]);

	while (pivot != nonPivot){
		if (nonPivotIsOnRight){
			if (numComp++, personArr[pivot].getPersonId() > personArr[nonPivot].getPersonId()) {
				swap(personArr[pivot], personArr[nonPivot]);
				swap(pivot, nonPivot);
				nonPivotIsOnRight = !nonPivotIsOnRight;
				nonPivot++;
			}
			else {
				nonPivot--;
			}
		}
		else {
			if (numComp++, personArr[nonPivot].getPersonId() > personArr[pivot].getPersonId()) {
				swap(personArr[nonPivot], personArr[pivot]);
				swap(nonPivot, pivot);
				nonPivotIsOnRight = !nonPivotIsOnRight;
				nonPivot--;
			}
			else {
				nonPivot++;
			}
		}
	}

	return pivot;
}

const Person& BST(vector<Person>& personArr, int k, int& numComp)
{
	BinarySearchTree bst;
	BinarySearchNode* res;
	bst.buildBST(personArr, numComp);
	res = bst.inOrderByIndexWrapper(k);
	return *(res->getPerson());
}
