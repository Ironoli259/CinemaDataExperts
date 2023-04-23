#include "User.h"

std::string User::getAgeClassification()
{
	return this->ageClassification;
}

const std::string& User::getUserName() const
{
	return this->userName;
}
