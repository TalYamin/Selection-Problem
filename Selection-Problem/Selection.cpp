#include "Selection.h"
#include "Heap.h"


/*
This function iimplements random selection algoritm, using select() call.
Function receivs person array, and returns the k largest element.
returns the relevant person from array.
*/
const Person& randSelection(vector<Person>& personArr, int k, int& numComp)
{
	Person* p;
	int left = 0;
	int right = personArr.size() - 1;
	p = select(personArr, left, right, k, numComp);
	return *p;
}

/*
This function is recursive function which implements the select algorithm.
Function receives the person array, left and right indexs and k size.
Function generate random index for pivot. There is call to partition function.
Then there are comprasions to K value. According to result, there is another
recursive call to select() with relevant part: if k is smaller than leftpart, 
so another call to select with left part. if it is bigger than leftpart, 
another call to select with right part.
*/
Person* select(vector<Person>& personArr, int left, int right, int k, int& numComp) {

	int randIndex;
	int pivotIndex;
	int leftPart;

	randIndex = left + (rand() % (right - left + 1));
	pivotIndex = partition(personArr, left, right, randIndex, numComp);
	leftPart = pivotIndex - left + 1;
	if (numComp++, k == leftPart) {
		return &personArr[pivotIndex];
	}
	if (numComp++, k < leftPart) {
		return select(personArr, left, pivotIndex - 1, k, numComp);
	}
	else {
		return select(personArr, pivotIndex + 1, right, k - leftPart, numComp);
	}
}


/*
This function implements partition algorithm. 
Function handles to indexes of pivot and non-pivot.
There are comprasion between them: if non-pivot is on right side, if pivot is bigger
then non-pivot - swap between them. if non-pivot is on left side, if non-pivot is bigger
then pivot - swap betwwen them.
non-pivot alwasy get ahead one step.
In the end,returns pivot.
*/
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

/*
This function implements select by heap algorithm.
Building heap, delete minimum k times. returns the the last minimum.
It is the k largest element.
returns the relevant person from array.
*/
const Person& selectHeap(vector<Person>& personArr, int k, int& numComp)
{
	Person* p = nullptr;
	Heap* heap = new Heap(personArr.size());
	heap->buildHeap(personArr, numComp);
	for (int i = 0; i < k; i++)
	{
		p = heap->deleteMin(numComp);
	}
	delete heap;
	return *p;
}

/*
This function implements select by binary search tree algorithm.
Building the tree. Then, call to inorder by index function which 
passes on all nodes by in order methods until arrived to the k largest element.
returns the relevant person from array.
*/
const Person& BST(vector<Person>& personArr, int k, int& numComp)
{
	BinarySearchTree bst;
	BinarySearchNode* res;
	bst.buildBST(personArr, numComp);
	res = bst.inOrderByIndexWrapper(k,numComp);
	return *(res->getPerson());
}


