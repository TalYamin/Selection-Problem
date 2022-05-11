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
void simplifyWhitespace(string& dst, const string src);
void ignoreSpacesUntilChar(const std::string& src, size_t& srcIndex);
void printResult(const string& resultType, const Person& person, const int& numComp);


/*
The aim of the program is to implement a number of solutions to the problem of selection, 
research and analysis the differences between the different solutions in relation to k and n.
There are three soultions which are checked in program: 
1) random selection 
2) selection by heap
3) selection by BST
Program receives array of persons and required k size,
then prints the k largest person id as result and in addition prints the number 
of comprasion which have been done in any type of solution.
*/
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
	printResult("RandSelection: ", p, numComp);
	numComp = 0;
	p = selectHeap(personArr, k, numComp);
	printResult("selectHeap: ", p, numComp);
	numComp = 0;
	p = BST(personArr, k, numComp);
	printResult("BST: ", p, numComp);
	return 0;
}



/*
This function responsible to get input from user.
In case there are persons with duplicate id, only one of them inserted to person array.
Then there is input validation which checks the input is valid.
*/
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

/*
Function check if the input is valid. 
*/
void isValidInput(vector<Person>& personArr, int numOfPersons, int k)
{
	if ((numOfPersons < 0) || (personArr.size() != numOfPersons) || (k >= numOfPersons) || (k < 1))
	{
		handleError();
	}
}


/*
This function is used to extract person from user.
At first, taking the string and simplfy it to be without duplicate spaces. 
Then, sepearte the infromation according to space betwwen the text.
Then, initialize the data members id and name.
*/
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

/*
This function is used to make string more simple by remove duplicate spaces.
*/
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

/*
This function responible to get a string and to ignoer spaces until 
enconter another char.
*/
void ignoreSpacesUntilChar(const string& src, size_t& srcIndex)
{

	if (isspace(src[srcIndex]))
		while (isspace(src[srcIndex + 1]))
			srcIndex++;
}

/*
This function prints the results.
*/
void printResult(const string& resultType, const Person& person, const int& numComp) {

	cout << resultType << person << " " << numComp << " comparisons" << endl;

}

