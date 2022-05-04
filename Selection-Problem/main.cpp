#include <cstdlib>
#include <iostream>
#include <string>
#include "Person.h"
#include "Selection.h"
#include <vector>

using namespace std;

void getInputFromUser(int& seed);

void main() {

	int seed = 0;
	int numOfPersons = 0;
	int k = 0;
	int numComp = 0;
	vector<Person> personArr;
	
	getInputFromUser(seed);
	srand(seed);

	
	randSelection(personArr, k, numComp);

}

void getInputFromUser(int& seed) {

	string tmp;
	getline(cin, tmp);
	seed = stoi(tmp);

}