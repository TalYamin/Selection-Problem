#pragma once

#include <string>
#include "Person.h"
#include <vector>

class Heap
{
	vector<Person*> data;
	int heapSize;
	bool allocated = false;
	static int Left(int node);
	static int Right(int node);
	static int Parent(int node);
	void getMin(int left, int node, int& min);
	void heapify(int node);
public:
	Heap(int max);
	~Heap();
	void buildHeap(vector<Person>& A);
	Person* min();
	Person* deleteMin();
	void makeEmpty();
	bool isEmpty();
	void insert(Person* p);
private:

};