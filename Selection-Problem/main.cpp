#include <iostream>
#include <string>
#include "Person.h"
#include "Selection.h"
#include <algorithm>
#include <vector>
#include "Utils.h"
#define DELIIMITER ' '

using namespace std;

void isValidInput(std::vector<Person>& personArr, int numOfPersons);
void getInputFromUser(int& seed, int& numOfPersons, vector<Person>& personArr, int& k);
void extractPersonFromInput(string input, Person& p);
bool comparePersonId(Person first, Person second);

void main() {

	int seed = 0;
	int numOfPersons = 0;
	int k = 0;
	int numComp = 0;
	vector<Person> personArr;
	Person p;

	getInputFromUser(seed, numOfPersons, personArr, k);
	isValidInput(personArr, numOfPersons);
	
	srand(seed);
	p = randSelection(personArr, k, numComp);
	cout << "RandSelection: " << p << " " << numComp << " comparisons" << endl;
	numComp = 0;
	p = selectHeap(personArr, k, numComp);
	cout << "selectHeap: " << p << " " << numComp << " comparisons" << endl;
	numComp = 0;
	p = BST(personArr, k, numComp);
	cout << "BST: " << p << " " << numComp << " comparisons" << endl;

}

bool comparePersonId(Person first, Person second)
{
	if (first.getPersonId() != second.getPersonId())
		return false;
	return true;
}

void getInputFromUser(int& seed, int& numOfPersons, vector<Person>& personArr, int& k) {

	Person p;
	string input;
	getline(cin, input);
	seed = stoi(input);
	getline(cin, input);
	numOfPersons = stoi(input);
	for (int i = 0; i < numOfPersons; i++) {
		getline(cin, input);
		extractPersonFromInput(input, p);
		personArr.push_back(p);
	}
	getline(cin, input);
	k = stoi(input);
}

void isValidInput(vector<Person>& personArr, int numOfPersons)
{
	bool isValid = true;
	personArr.erase(unique(personArr.begin(), personArr.end(), comparePersonId), personArr.end());
	if (personArr.size() != numOfPersons)
	{
		handleError();
	}

}



void extractPersonFromInput(string input, Person& p) {

	size_t pos = input.find(DELIIMITER);
	string token = input.substr(0, pos);
	p.setPersonId(stoi(token));
	token = input.erase(0, pos + 1);//include size of ' '
	p.setPerosnName(token);
}

