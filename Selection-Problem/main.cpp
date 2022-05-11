#include <iostream>
#include <string>
#include "Person.h"
#include "Selection.h"
#include <algorithm>
#include <vector>
#include "Utils.h"
#define DELIIMITER ' '

using namespace std;

void isValidInput(std::vector<Person>& personArr, int numOfPersons, int k);
void getInputFromUser(int& seed, int& numOfPersons, vector<Person>& personArr, int& k);
void extractPersonFromInput(string input, Person& p);
bool comparePersonId(Person first, Person second);
void simplifyWhitespace(string& dst, const string src);
void ignoreSpacesUntilChar(const std::string& src, size_t& srcIndex);

int main() {

	int seed = 0;
	int numOfPersons = 0;
	int k = 0;
	int numComp = 0;
	vector<Person> personArr;
	Person p;

	getInputFromUser(seed, numOfPersons, personArr, k);

	srand(seed);
	p = randSelection(personArr, k, numComp);
	cout << "RandSelection: " << p << " " << numComp << " comparisons" << endl;
	numComp = 0;
	p = selectHeap(personArr, k, numComp);
	cout << "selectHeap: " << p << " " << numComp << " comparisons" << endl;
	numComp = 0;
	p = BST(personArr, k, numComp);
	cout << "BST: " << p << " " << numComp << " comparisons" << endl;
	return 0;
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
		if (find(personArr.begin(), personArr.end(), p) == personArr.end())
			personArr.push_back(p);
	}
	getline(cin, input);
	k = stoi(input);
	isValidInput(personArr, numOfPersons, k);

}

void isValidInput(vector<Person>& personArr, int numOfPersons, int k)
{
	if ((numOfPersons < 0) || (personArr.size() != numOfPersons) || (k >= numOfPersons) || (k < 1))
	{
		handleError();
	}
}



void extractPersonFromInput(string input, Person& p) {

	string inputWithoutDuplicationSpaces;
	simplifyWhitespace(inputWithoutDuplicationSpaces, input);
	size_t pos = inputWithoutDuplicationSpaces.find(DELIIMITER);
	if (pos == string::npos)
	{
		handleError();
	}

	string token = inputWithoutDuplicationSpaces.substr(0, pos);
	p.setPersonId(stoi(token));
	token = inputWithoutDuplicationSpaces.erase(0, pos + 1);//include size of ' '
	pos = inputWithoutDuplicationSpaces.find(DELIIMITER);
	if (pos == string::npos)
	{
		handleError();
	}
	p.setPerosnName(token);
}

void simplifyWhitespace(string& dst, const string src)
{
	size_t srcIndex = 0;
	ignoreSpacesUntilChar(src, srcIndex);
	if (isspace(src[srcIndex]))
		srcIndex++;
	while (src[srcIndex] !='\0')
	{
		dst += src[srcIndex];
		ignoreSpacesUntilChar(src, srcIndex);
		srcIndex++;
	}
	dst += '\0';
}

void ignoreSpacesUntilChar(const string& src, size_t& srcIndex)
{

	if (isspace(src[srcIndex]))
		while (isspace(src[srcIndex + 1]))
			srcIndex++;
}



