#pragma once

#include <string>
#include "Person.h"
#include <vector>
#include "Utils.h"

class Heap
{
	vector<Person*> data;
	int heapSize;
	bool allocated = false;
	
public:
	Heap(int max);
	~Heap();
	void buildHeap(vector<Person>& A, int& numComp);
	Person* min();
	Person* deleteMin(int& numComp);
	void makeEmpty(int& numComp);
	bool isEmpty();
	void insert(Person* p, int& numComp);
private:
	static int Left(int node);
	static int Right(int node);
	static int Parent(int node);
	void getMin(int left, int node, int& min, int& numComp);
	void heapify(int node, int& numComp);
};