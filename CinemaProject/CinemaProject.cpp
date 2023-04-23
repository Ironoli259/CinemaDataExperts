#include <iostream>
#include "CinemaReservation.h"
#include "Administrator.h"

using namespace std;

int mainMenu() {
	int input;

	do {
		cout << "          Welcome          \n";
		cout << "---------------------------\n";
		cout << "1 - LOG IN\n";
		cout << "2 - CREATE NEW USER\n";
		cout << "3 - ADMINISTRATION\n";
		cout << "4 - EXIT\n";
		cin >> input;
		system("cls");
	} while (cin.fail() || input < 1 || input > 4);

	return input;
}

int main()
{
	int input;
	std::string userName;
	Administrator admin = Administrator("ADMIN");
	CinemaReservation* cinemaReservation = new CinemaReservation();
	cinemaReservation->Initialize();
	do {
		input = mainMenu();
		auto it = cinemaReservation->GetUserList().end();
		
		switch (input)
		{
		case 1:
		{
			cout << "           LOG IN          \n";
			cout << "---------------------------\n";
			cout << "Username: ";
			cin >> userName;
			system("cls");

			//Verify if user exists
			it = std::find_if(cinemaReservation->GetUserList().begin(), cinemaReservation->GetUserList().end(), [&](const User* user) {
				return user->getUserName() == userName;
				});
			if (it != cinemaReservation->GetUserList().end()) {
				cinemaReservation->SetCurrentUser(*it);
				cinemaReservation->MainMenu();
			}
			else {
				cout << "The user does not exist. Please create a new user.\n";
				system("pause");
				system("cls");
			}
			break;
		}
		case 2:
			cout << "           CREATE A USER          \n";
			cout << "----------------------------------\n";
			cout << "Enter a username: ";

			while (!(cin >> userName) || userName.empty()) {
				cout << "INVALID INPUT\n";
				cout << "Enter a username: ";
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			//Verify if user exists
			it = std::find_if(cinemaReservation->GetUserList().begin(), cinemaReservation->GetUserList().end(), [&](const User* user) {
				return user->getUserName() == userName;
				});
			if (it != cinemaReservation->GetUserList().end()) {
				cout << "The username already exists.\n";
				system("pause");
				system("cls");
			}
			else {
				cinemaReservation->AddUser(userName);				
			}
			break;
		case 3:
			break;
		default:
			cinemaReservation->ExitApp();
		}
	} while (input != 4);

	delete cinemaReservation;
	return 0;
}
