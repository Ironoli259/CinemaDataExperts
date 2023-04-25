#pragma once
#include <string>

struct Employee {
	int id;
	std::string name;
	std::string job;
	float salary;

	Employee(const int& id, const std::string& name, std::string job, float salary) : id(id), name(name), job(job), salary(salary) {}
};

class Administrator
{
private:
	std::string userName;		

public:
	Administrator(std::string userName);
	~Administrator();
	void viewSales();
	void manageEmployees();
	void manageMovies();	//Add or Remove movies
	void manageShowtimes();
};

