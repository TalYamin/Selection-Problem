#include "Selection.h"

const Person& RandSelection(vector<Person>& personArr, int k, int& NumComp)
{
	
	int randIndex;
	int pivotIndex;
	int left = 0;
	int right = personArr.size()-1;
	int leftPart;

	randIndex = rand() % personArr.size();
	pivotIndex = partition(personArr, left, right, randIndex);

}

int partition(vector<Person>& personArr, int left, int right, int randIndex) {

	int pivot = left;
	int nonPivot = right;
	bool nonPivotIsOnLeft = true;

	swap(personArr[left], personArr[randIndex]);

	while (pivot != nonPivot){
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
}
