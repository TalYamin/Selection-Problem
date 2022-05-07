#pragma once

#include <string>
#include <ostream>

using namespace std;


class Person {

	int personId = 0;
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
	friend ostream& operator<<(ostream& os, const Person& p) {
		return os << p.personId << " " << p.personName;
	}
};