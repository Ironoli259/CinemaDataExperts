#include "Administrator.h"

Administrator::Administrator(std::string userName, std::string password, bool main)
{
	this->userName = userName;
	this->password = password;
	this->isMainAdmin = main;
}

Administrator::~Administrator()
{
	//Not implemented.
	//Need to make it so the main Admin cannot be deleted.
}

void Administrator::viewSales()
{
	//Not implemented
}

void Administrator::manageEmployees()
{
	//Not implemented
}

void Administrator::manageMovies()
{
	//Not implemented
}

void Administrator::manageShowtimes()
{
	//Not implemented
}
