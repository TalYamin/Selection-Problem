#include "Heap.h"
#include <iostream>

/*
This function returns the index of parent node
*/
int Heap::Parent(int node)
{
	return (node - 1) / 2;
}

/*
This function returns the the index of left child
*/
int Heap::Left(int node)
{
	return (2 * node + 1);
}

/*
This function returns the index of right child
*/
int Heap::Right(int node)
{
	return (2 * node + 2);
}

/*
This function is used to fix heap structure. 
Function makes comparsions between nodes, and raise to top the minimum value.
*/
void Heap::heapify(int node, int& numComp)
{
	int min;
	int left = Left(node);
	int right = Right(node);
	if ((left < heapSize) && ++numComp && (data[left]->getPersonId() < data[node]->getPersonId()))
	{
		min = left;
	}
	else {
		min = node;
	}
	if ((right < heapSize) && ++numComp && (data[right]->getPersonId() < data[min]->getPersonId())) 
	{
		min = right;
	}

	if (min != node)
	{
		swap(data[node], data[min]);
		heapify(min,numComp);
	}
}

/*
ctor of heap with 1 parameter
*/
Heap::Heap(int max)
{
	data.resize(max);
	heapSize = 0;
	allocated = true;
}

/*
This function builds heap. Function receives person array 
and insert the elemetns to the array which represent heap.
*/
void Heap::buildHeap(vector<Person>& arr, int& numComp)
{
	heapSize = arr.size();
	data.resize(arr.size());
	for (int i = 0;i < arr.size();i++)
	{
		data[i] = &arr[i];
	}
	for (int i = arr.size() / 2 - 1;i >= 0;i--)
	{
		heapify(i,numComp);
	}
}

/*
dtor of heap
*/
Heap::~Heap(){
}

/*
Function returens the minimum from heap.
*/
Person* Heap::min()
{
	if (isEmpty()){
		handleError();
	}
	return data[0];
}

/*
Function delete the minimum from heap.
*/
Person* Heap::deleteMin(int& numComp)
{
	if (isEmpty()){
		handleError();
	}
	Person* p = data[0];
	heapSize--;
	data[0] = data[heapSize];
	heapify(0,numComp);
	return p;
}

/*
This function is used to make heap empty.
*/
void Heap::makeEmpty(int& numComp)
{
	while (heapSize != 0)
	{
		deleteMin(numComp);
	}
}

/*
This function checks if heap is empty.
*/
bool Heap::isEmpty()
{
	if (data.size() < 1)
		return true;
	return false;
}

/*
This function repsonible to insert person pointer as an
elemnet to heap.
*/
void Heap::insert(Person* p, int& numComp)
{
	if (heapSize == data.size()){
		handleError();
	}
	int i = heapSize;
	heapSize++;
	while ((i > 0) && ++numComp && data[Parent(i)]->getPersonId() > p->getPersonId())
	{
		data[i] = data[Parent(i)];
		i = Parent(i);
	}
	data[i] = p;
}
