#pragma once
#include "Person.h"
#include "vector"


const Person& randSelection(vector<Person>& personArr, int k, int& numComp);
Person* select(vector<Person>& personArr, int left, int right, int k, int& numComp);
int partition(vector<Person>& personArr, int left, int right, int randIndex, int& numComp);
const Person& selectHeap(vector<Person>& personArr, int k, int& numComp);