#include <cstdlib>
#include <iostream>
#include <string>
#include "Person.h"
#include "Selection.h"
#include <vector>
#define DELIIMITER ' '

using namespace std;

void getInputFromUser(int& seed, int& numOfPersons, vector<Person>& personArr, int& k);
void extractPersonFromInput(string input, Person& p);

void main() {

	int seed = 0;
	int numOfPersons = 0;
	int k = 0;
	int numComp = 0;
	vector<Person> personArr;
	Person p;

	getInputFromUser(seed,numOfPersons, personArr, k);
	srand(seed);
	//p = randSelection(personArr, k, numComp);
	p = BST(personArr, k, numComp);
}

void getInputFromUser(int& seed, int& numOfPersons, vector<Person>& personArr, int& k) {

	Person p;
	string input;
	getline(cin, input);
	seed = stoi(input);
	getline(cin, input);
	numOfPersons = stoi(input);
	for (int i = 0; i < numOfPersons; i++){
		getline(cin, input);
		extractPersonFromInput(input, p);
		personArr.push_back(p);
	}
	getline(cin, input);
	k = stoi(input);
}

void extractPersonFromInput(string input, Person& p) {

	size_t pos = input.find(DELIIMITER);
	string token = input.substr(0, pos);
	p.setPersonId(stoi(token));
	token = input.erase(0, pos + 1);//include size of ' '
	p.setPerosnName(token);
}

