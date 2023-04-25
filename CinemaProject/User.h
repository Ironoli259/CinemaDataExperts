#pragma once
#include <string>
#include <stack>
#include "MovieList.h"

struct Ticket {
	Movie* movie;
	std::string startTime;
	int hall;

	Ticket(Movie* movie, std::string startTime, int hall): movie(movie), startTime(startTime), hall(hall){}
};

class User
{
private:
	std::string userName;
	std::string firstName;
	std::string lastName;
	std::string ageClassification;
	std::stack<Ticket*> purchasedTickets; // Stack to store purchased tickets

public:
	std::string preferredGenre;
	std::string preferredDirector;
	std::string preferredActor;

	User(std::string userName, std::string firstName, std::string lastName, std::string ageClass) : userName(userName), firstName(firstName), lastName(lastName), ageClassification(ageClass){}
	std::string getAgeClassification();
	const std::string& getUserName() const;

	void AddPurchasedTickets(Movie* movie, std::string startTime, int hall);
	void DisplayTickets() const;
};

