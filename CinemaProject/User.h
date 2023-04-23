#pragma once
#include <string>;

class User
{
private:
	std::string userName;
	std::string name;
	std::string ageClassification;

	std::string preferredClassification;
	std::string preferredGenre;
	std::string preferredDirector;
	std::string preferredActor;

public:
	const std::string& getUserName() const;

};

