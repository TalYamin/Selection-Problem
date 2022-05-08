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

void Heap::getMin(int left, int node, int& min)
{

	if ((left < heapSize) && (data[left]->getPersonId() < data[node]->getPersonId()))
	{
		min = left;
	}
	else
		min = node;
}

void Heap::heapify(int node)
{
	int min;
	int left = Left(node);
	int right = Right(node);
	if ((left < heapSize) && (data[left]->getPersonId() < data[node]->getPersonId()))
	{
		min = left;
	}
	else {
		min = node;
	}
	if ((right < heapSize) && (data[right]->getPersonId() < data[min]->getPersonId()))
	{
		min = right;
	}

	if (min != node)
	{
		swap(data[node], data[min]);
		heapify(min);
	}
}

Heap::Heap(int max)
{
	data.resize(max);
	heapSize = 0;
	allocated = true;
}

void Heap::buildHeap(vector<Person>& arr)
{
	heapSize = arr.size();
	data.resize(arr.size());
	for (int i = 0;i < arr.size();i++)
	{
		data[i] = &arr[i];
	}
	for (int i = arr.size() / 2 - 1;i >= 0;i--)
	{
		heapify(i);
	}
}

Heap::~Heap()
{
	if (allocated)
	{
		for (int i = 0;i < data.size();i++)
		{
			delete(data[i]);
		}
	}
}

Person* Heap::min()
{
	if (isEmpty())
	{
		cout << "Handle Error";
	}
	return data[0];
}

Person* Heap::deleteMin()
{
	if (isEmpty())
	{
		cout << "Handle Error";
	}
	Person* p = data[0];
	heapSize--;
	data[0] = data[heapSize];
	heapify(0);
	return p;
}

void Heap::makeEmpty()
{
	while (heapSize != 0)
	{
		deleteMin();
	}
}

bool Heap::isEmpty()
{
	if (data.size() < 1)
		return true;
	return false;
	return false;
}

void Heap::insert(Person* p)
{
	if (heapSize == data.size())
	{
		cout << "handle Error";
		return;
	}
	int i = heapSize;
	heapSize++;
	while ((i > 0) && data[Parent(i)]->getPersonId() > p->getPersonId())
	{
		data[i] = data[Parent(i)];
		i = Parent(i);
	}
	data[i] = p;
}
