#pragma once
#include "User.h"
#include <vector>
class CinemaReservation
{
private:
public:
	std::vector<User> userList;
	void Initialize();
	void MainMenu();
	void SearchMovieMenu();
	void ExitApp();
};

