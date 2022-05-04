#pragma once

#include <string>
using namespace std;


class Person {

	int personId;
	string personName;

public:
	
	//ctors + dtors
	Person() = default;
	Person(int _personId, string _personName);
	~Person();

	//gettters + setters
	int getPersonId();
	void setPersonId(int _personId);
	string getPersonName();
	void setPerosnName(string _personName);
};