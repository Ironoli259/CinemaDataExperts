#include "User.h"
#include <iostream>

std::string User::getAgeClassification()
{
	return this->ageClassification;
}

const std::string& User::getUserName() const
{
	return this->userName;
}

void User::AddPurchasedTickets(Movie* movie, std::string startTime, int hall)
{
    Ticket* newTicket = new Ticket(movie, startTime, hall);
	purchasedTickets.push(newTicket);
}

void User::DisplayTickets() const
{
    if (purchasedTickets.empty()) {
        std::cout << "No ticket reservations found for this user.\n";
        return;
    }

    std::cout << "Ticket reservations\n";
    std::stack<Ticket*> tempStack = purchasedTickets; // Copy stack to a temporary stack to avoid modifying original stack
    while (!tempStack.empty()) {
        Ticket* ticket = tempStack.top();
        std::cout << ticket->startTime << " - Hall " << ticket->hall << " - " << ticket->movie->title << std::endl;
        tempStack.pop();
    }
}
