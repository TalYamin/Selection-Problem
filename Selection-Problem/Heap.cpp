#include "Heap.h"
#include <iostream>

int Heap::Parent(int node)
{
	return (node - 1) / 2;
}
int Heap::Left(int node)
{
	return (2 * node + 1);
}
int Heap::Right(int node)
{
	return (2 * node + 2);
}


void Heap::heapify(int node, int& numComp)
{
	int min;
	int left = Left(node);
	int right = Right(node);
	if (numComp++, (left < heapSize) && (data[left]->getPersonId() < data[node]->getPersonId()))
	{
		min = left;
	}
	else {
		min = node;
	}
	if (numComp++, (right < heapSize) && (data[right]->getPersonId() < data[min]->getPersonId()))
	{
		min = right;
	}

	if (min != node)
	{
		swap(data[node], data[min]);
		heapify(min,numComp);
	}
}

Heap::Heap(int max)
{
	data.resize(max);
	heapSize = 0;
	allocated = true;
}

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

Heap::~Heap(){
}

Person* Heap::min()
{
	if (isEmpty()){
		handleError();
	}
	return data[0];
}

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

void Heap::makeEmpty(int& numComp)
{
	while (heapSize != 0)
	{
		deleteMin(numComp);
	}
}

bool Heap::isEmpty()
{
	if (data.size() < 1)
		return true;
	return false;
}

void Heap::insert(Person* p, int& numComp)
{
	if (heapSize == data.size()){
		handleError();
	}
	int i = heapSize;
	heapSize++;
	while (numComp++, (i > 0) && data[Parent(i)]->getPersonId() > p->getPersonId())
	{
		data[i] = data[Parent(i)];
		i = Parent(i);
	}
	data[i] = p;
}
