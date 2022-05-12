#pragma once

#include <string>
#include "Person.h"
#include <vector>
#include "Utils.h"

class Heap
{
	//data members
	vector<Person*> data;
	int heapSize;
	bool allocated = false;
	
public:

	//ctors + dtors
	Heap(int max);
	~Heap();

	//public functions
	void buildHeap(vector<Person>& A, int& numComp);
	Person* min();
	Person* deleteMin(int& numComp);
	void makeEmpty(int& numComp);
	bool isEmpty();
	void insert(Person* p, int& numComp);

private:

	//private functions
	static int Left(int node);
	static int Right(int node);
	static int Parent(int node);
	void heapify(int node, int& numComp);
};