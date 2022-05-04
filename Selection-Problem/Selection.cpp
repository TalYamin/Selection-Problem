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

	randIndex = rand() % personArr.size();
	pivotIndex = partition(personArr, left, right, randIndex, numComp);
	leftPart = pivotIndex - left + 1;
	numComp++;
	if (k == leftPart){
		return &personArr[pivotIndex];
	}
	numComp++;
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
	bool nonPivotIsOnLeft = true;

	swap(personArr[left], personArr[randIndex]);

	while (pivot != nonPivot){
		numComp++;
		if (personArr[pivot].getPersonId() > personArr[nonPivot].getPersonId()){
			swap(personArr[pivot], personArr[nonPivot]);
		}
		if (nonPivotIsOnLeft){
			nonPivot--;
		}
		else {
			nonPivot++;
		}
	}

	return pivot;
}
