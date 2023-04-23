#pragma once
#include <iostream>
#include "User.h"
#include "MovieList.h"
#include "HallsTree.h"
#include <vector>
#include <queue>

struct TicketReservation {
	int hallNumber;
	int showTimeIndex;
	int numberOfTickets;
};

class CinemaReservation
{
private:
	std::queue<TicketReservation> ticketReservations;
	std::vector<User*> userList;
	User* currentUser;
public:	
	void Initialize();
	void MainMenu();
	Movie* SearchMovieMenu();
	CinemaHall* SearchHallsMenu();
	void ExitApp();
	std::vector<User*> GetUserList();
	void SetCurrentUser(User* user);
	void AddUser(std::string userName);
	std::string CalculateEndTime(int hours, int minutes, int minsToAdd);
};

