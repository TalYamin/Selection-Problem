#include "Person.h"

Person::Person(int _personId, string _personName)
{
	personId = _personId;
	personName = _personName;
}

Person::~Person()
{
}

int Person::getPersonId()
{
	return personId;
}

void Person::setPersonId(int _personId){
	personId = _personId;
}

string Person::getPersonName()
{
	return personName;
}

void Person::setPerosnName(string _personName){

	personName = _personName;

}
