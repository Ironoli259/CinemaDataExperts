#pragma once
#include <iostream>
#include "User.h"
#include "MovieList.h"
#include "HallsTree.h"
#include <vector>
#include <queue>

struct TicketReservation {
	int hallNumber;
	std::string startTime;
	int numberOfTickets;
	std::string username;

	TicketReservation(int hall, std::string time, int numberOfTickets, std::string user): hallNumber(hall), startTime(time), numberOfTickets(numberOfTickets), username(user) {}
};

class CinemaReservation
{
private:
	std::queue<TicketReservation> ticketReservationRequests;
	std::vector<User*> userList;
	User* currentUser;
public:	
	CinemaReservation() : currentUser(nullptr){}
	~CinemaReservation() {
		for (auto user : userList) {
			delete user;
		}
	}

	void Initialize();
	void MainMenu();
	Movie* SearchMovieMenu();
	Showtime* ChooseShowtime(std::string movieTitle);
	Showtime* ChooseShowtime(int hallNumber);
	int SearchHallsMenu();
	void ExitApp();
	std::vector<User*>& GetUserList() { return userList; }
	void SetCurrentUser(User* user);
	void AddUser(std::string userName);
	std::string CalculateEndTime(int hours, int minutes, int minsToAdd);
	int ReserveTickets(Showtime* showtime);
	void AddTicket(Showtime* showtime, int amount);
};

