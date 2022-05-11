#include "Person.h"

/*
ctor of person with 2 parameters 
*/
Person::Person(int _personId, string _personName)
{
	personId = _personId;
	personName = _personName;
}

//dtor of person
Person::~Person()
{
}

//Only unique id used for compare between to persons.
bool Person::operator==(const Person& p)
{
	return (p.personId == personId);
}

//getter of personId data member
int Person::getPersonId()
{
	return personId;
}

//setter of personId data member
void Person::setPersonId(int _personId) {
	personId = _personId;
}

//getter of person name data member
string Person::getPersonName()
{
	return personName;
}

//setter of person name data member
void Person::setPerosnName(string _personName) {

	personName = _personName;

}

