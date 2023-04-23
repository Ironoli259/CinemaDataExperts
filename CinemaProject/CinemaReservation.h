#pragma once
#include "User.h"
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
	void SearchMovieMenu();
	void ExitApp();
	std::vector<User*> GetUserList();
	void SetCurrentUser(User* user);
	void AddUser(std::string userName);
};