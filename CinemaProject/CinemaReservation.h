#pragma once
#include "User.h"
#include <vector>
class CinemaReservation
{
private:
	std::vector<User> userList;
public:
	void Initialize();
	void MainMenu();
	void SearchMovieMenu();
	void ExitApp();
};

