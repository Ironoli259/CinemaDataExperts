#pragma once
#include <string>
class Administrator
{
private:
	std::string userName;
	std::string password;

public:
	Administrator(std::string userName, std::string password);
	~Administrator();
	void viewSales();
	void manageEmployees();
	void manageMovies();	//Add or Remove movies
	void manageShowtimes();
};

