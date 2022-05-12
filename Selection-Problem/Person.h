#pragma once

#include <string>
#include <ostream>

using namespace std;


class Person {

	//data members
	int personId = 0;
	string personName;

public:
	
	//ctors + dtors
	Person() = default;
	Person(int _personId, string _personName);
	~Person();

	//operators overloading
	bool operator==(const Person& p);
	friend ostream& operator<<(ostream& os, const Person& p) {
		return os << p.personId << " " << p.personName;
	}

	//gettters + setters
	int getPersonId();
	void setPersonId(int _personId);
	string getPersonName();
	void setPerosnName(string _personName);
	
};