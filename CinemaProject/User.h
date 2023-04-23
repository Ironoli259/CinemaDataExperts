#pragma once
#include <string>

class User
{
private:
	std::string userName;
	std::string firstName;
	std::string lastName;
	std::string ageClassification;

public:
	std::string preferredGenre;
	std::string preferredDirector;
	std::string preferredActor;

	User(std::string userName, std::string firstName, std::string lastName, std::string ageClass) : userName(userName), firstName(firstName), lastName(lastName), ageClassification(ageClass){}
	std::string getAgeClassification();
	const std::string& getUserName() const;

};

