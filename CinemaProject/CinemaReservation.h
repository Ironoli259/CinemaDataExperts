#pragma once
#include <iostream>
#include "User.h"
#include "MovieList.h"
#include "HallsTree.h"
#include <vector>
class CinemaReservation
{
private:
public:
	std::vector<User> userList;
	void Initialize();
	void MainMenu();
	Movie* SearchMovieMenu();
	CinemaHall* SearchHallsMenu();
	void ExitApp();
	std::string CalculateEndTime(int hours, int minutes, int minsToAdd);
};

