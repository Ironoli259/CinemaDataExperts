#include <iostream>
#include <string>
#include <regex>
#include "CinemaReservation.h"
#include "MovieList.h"
#include "HallsTree.h"
#include "ShowtimeList.h"
#include "MiscMethods.h"
#include <chrono>
#include <thread>
#include <cstdlib>
#include <string> 
#include <memory>
#include <limits>

using namespace std::chrono_literals;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

MovieList movieList;
HallsTree hallsList;
ShowtimeList showList;
void CinemaReservation::Initialize()
{
	int nbrMovies{ 24 };
	int hallsIndex{ 1 };
	int showIndex{ 0 };
	int movieIndex{ nbrMovies - 1 };
	int duration{ 0 };

	User* olivier = new User("Oli", "Olivier", "Grenier", "M");
	olivier->preferredGenre = "Adventure";
	olivier->preferredDirector = "Peter Jackson";
	olivier->preferredActor = "Leonardo DiCaprio";
	this->userList.push_back(olivier);

	movieList.addMovie("The Shawshank Redemption", 142, "R", "Two imprisoned men bond over a number of years, finding solace and eventual redemption through acts of common decency.", "Drama", "Frank Darabont", "Tim Robbins", 9.3f);
	movieList.addMovie("The Godfather", 175, "R", "The aging patriarch of an organized crime dynasty transfers control of his clandestine empire to his reluctant son.", "Crime", "Francis Ford Coppola", "Marlon Brando", 9.2f);
	movieList.addMovie("The Dark Knight", 152, "PG-13", "When the menace known as the Joker wreaks havoc and chaos on the people of Gotham, Batman must accept one of the greatest psychological and physical tests of his ability to fight injustice.", "Action", "Christopher Nolan", "Christian Bale", 9.0f);
	movieList.addMovie("Schindler's List", 195, "R", "In German-occupied Poland during World War II, industrialist Oskar Schindler gradually becomes concerned for his Jewish workforce after witnessing their persecution by the Nazis.", "Biography", "Steven Spielberg", "Liam Neeson", 8.9f);
	movieList.addMovie("The Lord of the Rings: The Return of the King", 201, "PG-13", "Gandalf and Aragorn lead the World of Men against Sauron's army to draw his gaze from Frodo and Sam as they approach Mount Doom with the One Ring.", "Adventure", "Peter Jackson", "Elijah Wood", 8.9f);
	movieList.addMovie("Pulp Fiction", 154, "R", "The lives of two mob hitmen, a boxer, a gangster and his wife, and a pair of diner bandits intertwine in four tales of violence and redemption.", "Crime", "Quentin Tarantino", "John Travolta", 8.9f);
	movieList.addMovie("The Lord of the Rings: The Fellowship of the Ring", 178, "PG-13", "A meek Hobbit from the Shire and eight companions set out on a journey to destroy the powerful One Ring and save Middle-earth from the Dark Lord Sauron.", "Adventure", "Peter Jackson", "Elijah Wood", 8.8f);
	movieList.addMovie("Forrest Gump", 142, "PG-13", "The presidencies of Kennedy and Johnson, the events of Vietnam, Watergate, and other history unfold through the perspective of an Alabama man with an IQ of 75.", "Drama", "Robert Zemeckis", "Tom Hanks", 8.8f);
	movieList.addMovie("Inception", 148, "PG-13", "A thief who steals corporate secrets through the use of dream-sharing technology is given the inverse task of planting an idea into the mind of a CEO.", "Action", "Christopher Nolan", "Leonardo DiCaprio", 8.7f);
	movieList.addMovie("The Lord of the Rings: The Two Towers", 179, "PG-13", "While Frodo and Sam edge closer to Mordor with the help of the shifty Gollum, the divided fellowship makes a stand against Sauron's new ally, Saruman, and his hordes of Isengard.", "Adventure", "Peter Jackson", "Elijah Wood", 8.7f);
	movieList.addMovie("The Matrix", 136, "R", "A computer hacker learns from mysterious rebels about the true nature of his reality and his role in the war against its controllers.", "Action", "Lana Wachowski", "Keanu Reeves", 8.7f);
	movieList.addMovie("The Silence of the Lambs", 118, "R", "A young F.B.I. cadet must receive the help of an incarcerated and manipulative cannibal killer to help catch another serial killer.", "Thriller", "Jonathan Demme", "Jodie Foster", 8.6f);
	movieList.addMovie("Saving Private Ryan", 169, "R", "Following the Normandy Landings, a group of U.S. soldiers go behind enemy lines to retrieve a paratrooper whose brothers have been killed in action.", "War", "Steven Spielberg", "Tom Hanks", 8.6f);
	movieList.addMovie("Interstellar", 169, "PG-13", "A team of explorers travel through a wormhole in space in an attempt to ensure humanity's survival.", "Sci-Fi", "Christopher Nolan", "Matthew McConaughey", 8.6f);
	movieList.addMovie("Gladiator", 155, "R", "A former Roman General sets out to exact vengeance against the corrupt emperor who murdered his family and sent him into slavery.", "Action", "Ridley Scott", "Russell Crowe", 8.5f);
	movieList.addMovie("Joker", 122, "R", "In Gotham City, mentally troubled comedian Arthur Fleck is disregarded and mistreated by society. He then embarks on a downward spiral of revolution and bloody crime. This path brings him face-to-face with his alter-ego: the Joker.", "Crime", "Todd Phillips", "Joaquin Phoenix", 8.4f);
	movieList.addMovie("The Prestige", 130, "PG-13", "After a tragic accident, two stage magicians engage in a battle to create the ultimate illusion while sacrificing everything they have to outwit each other.", "Drama", "Christopher Nolan", "Hugh Jackman", 8.4f);
	movieList.addMovie("The Usual Suspects", 106, "R", "A sole survivor tells of the twisty events leading up to a horrific gun battle on a boat, which began when five criminals met at a seemingly random police lineup.", "Crime", "Bryan Singer", "Kevin Spacey", 8.4f);
	movieList.addMovie("Back to the Future", 116, "PG", "Marty McFly, a 17-year-old high school student, is accidentally sent thirty years into the past in a time-traveling DeLorean invented by his close friend, the eccentric scientist Doc Brown.", "Adventure", "Robert Zemeckis", "Michael J. Fox", 8.4f);
	movieList.addMovie("The Lion King", 88, "G", "Lion prince Simba and his father are targeted by his bitter uncle, who wants to ascend the throne himself.", "Animation", "Roger Allers", "Matthew Broderick", 8.3f);
	movieList.addMovie("Goodfellas", 146, "R", "The story of Henry Hill and his life in the mob, covering his relationship with his wife Karen Hill and his mob partners Jimmy Conway and Tommy DeVito in the Italian-American crime syndicate.", "Crime", "Martin Scorsese", "Robert De Niro", 8.7f);
	movieList.addMovie("Se7en", 127, "R", "Two detectives, a rookie and a veteran, hunt a serial killer who uses the seven deadly sins as his motives.", "Crime", "David Fincher", "Brad Pitt", 8.6f);
	movieList.addMovie("The Green Mile", 189, "R", "The lives of guards on Death Row are affected by one of their charges: a black man accused of child murder and rape, yet who has a mysterious gift.", "Drama", "Frank Darabont", "Tom Hanks", 8.6f);
	movieList.addMovie("Leon: The Professional", 110, "R", "Mathilda, a 12-year-old girl, is reluctantly taken in by L�on, a professional assassin, after her family is murdered. An unusual relationship forms as she becomes his prot�g�e and learns the assassin's trade.", "Crime", "Luc Besson", "Jean Reno", 8.5f);

	//hall 1
	//"The Shawshank Redemption"
	duration = 142;
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Monday to Friday at 15h15", CalculateEndTime(15, 15, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Monday to Friday at 18h15", CalculateEndTime(18, 15, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Monday to Friday at 21h15", CalculateEndTime(21, 15, duration), hallsIndex);
	movieIndex--;
	//"The Godfather"
	duration = 175;
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Saturday, Sunday at 15h25", CalculateEndTime(15, 25, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Saturday, Sunday at 18h25", CalculateEndTime(18, 25, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Saturday, Sunday at 21h25", CalculateEndTime(21, 25, duration), hallsIndex);
	movieIndex--;
	hallsList.AddHall(hallsIndex, &showList.getShowtimeAt(showIndex), &showList.getShowtimeAt(showIndex + 1), &showList.getShowtimeAt(showIndex + 2), &showList.getShowtimeAt(showIndex + 3), &showList.getShowtimeAt(showIndex + 4), &showList.getShowtimeAt(showIndex + 5));
	hallsIndex++;
	showIndex += 6;
	//Hall 2
	//"The Dark Knight"
	duration = 152;
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Monday to Friday at 15h00", CalculateEndTime(15, 0, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Monday to Friday at 18h00", CalculateEndTime(18, 0, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Monday to Friday at 21h00", CalculateEndTime(21, 0, duration), hallsIndex);
	movieIndex--;
	//"Schindler's List"
	duration = 195;
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Saturday, Sunday at 14h30", CalculateEndTime(14, 30, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Saturday, Sunday at 17h55", CalculateEndTime(17, 55, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Saturday, Sunday at 21h15", CalculateEndTime(21, 15, duration), hallsIndex);
	movieIndex--;
	hallsList.AddHall(hallsIndex, &showList.getShowtimeAt(showIndex), &showList.getShowtimeAt(showIndex + 1), &showList.getShowtimeAt(showIndex + 2), &showList.getShowtimeAt(showIndex + 3), &showList.getShowtimeAt(showIndex + 4), &showList.getShowtimeAt(showIndex + 5));
	hallsIndex++;
	showIndex += 6;
	//Hall 3
	//"The Lord of the Rings: The Return of the King"
	duration = 201;
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Monday to Friday at 13h45", CalculateEndTime(13, 45, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Monday to Friday at 17h55", CalculateEndTime(17, 55, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Monday to Friday at 22h15", CalculateEndTime(22, 15, duration), hallsIndex);
	movieIndex--;
	//"Pulp Fiction"
	duration = 154;
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Saturday, Sunday at 14h25", CalculateEndTime(14, 25, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Saturday, Sunday at 18h15", CalculateEndTime(18, 15, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Saturday, Sunday at 22h15", CalculateEndTime(22, 15, duration), hallsIndex);
	movieIndex--;
	hallsList.AddHall(hallsIndex, &showList.getShowtimeAt(showIndex), &showList.getShowtimeAt(showIndex + 1), &showList.getShowtimeAt(showIndex + 2), &showList.getShowtimeAt(showIndex + 3), &showList.getShowtimeAt(showIndex + 4), &showList.getShowtimeAt(showIndex + 5));
	hallsIndex++;
	showIndex += 6;
	//Hall 4
	//"The Lord of the Rings: The Fellowship of the Ring"
	duration = 178;
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Monday to Friday at 14h45", CalculateEndTime(14, 45, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Monday to Friday at 18h00", CalculateEndTime(18, 0, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Monday to Friday at 22h15", CalculateEndTime(22, 15, duration), hallsIndex);
	movieIndex--;
	//"Forrest Gump"
	duration = 142;
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Saturday, Sunday at 15h25", CalculateEndTime(15, 25, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Saturday, Sunday at 18h25", CalculateEndTime(18, 25, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Saturday, Sunday at 21h25", CalculateEndTime(21, 25, duration), hallsIndex);
	movieIndex--;
	hallsList.AddHall(hallsIndex, &showList.getShowtimeAt(showIndex), &showList.getShowtimeAt(showIndex + 1), &showList.getShowtimeAt(showIndex + 2), &showList.getShowtimeAt(showIndex + 3), &showList.getShowtimeAt(showIndex + 4), &showList.getShowtimeAt(showIndex + 5));
	hallsIndex++;
	showIndex += 6;
	//Hall 5
	//"Inception", 148
	duration = 148;
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Monday to Friday at 15h35", CalculateEndTime(15, 35, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Monday to Friday at 18h35", CalculateEndTime(18, 35, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Monday to Friday at 21h35", CalculateEndTime(21, 35, duration), hallsIndex);
	movieIndex--;
	//"The Lord of the Rings: The Two Towers", 179
	duration = 179;
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Saturday, Sunday at 14h45", CalculateEndTime(14, 45, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Saturday, Sunday at 18h00", CalculateEndTime(18, 0, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Saturday, Sunday at 21h25", CalculateEndTime(21, 25, duration), hallsIndex);
	movieIndex--;
	hallsList.AddHall(hallsIndex, &showList.getShowtimeAt(showIndex), &showList.getShowtimeAt(showIndex + 1), &showList.getShowtimeAt(showIndex + 2), &showList.getShowtimeAt(showIndex + 3), &showList.getShowtimeAt(showIndex + 4), &showList.getShowtimeAt(showIndex + 5));
	hallsIndex++;
	showIndex += 6;
	//Hall 6
	//"The Matrix", 136
	duration = 136;
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Monday to Friday at 15h35", CalculateEndTime(15, 35, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Monday to Friday at 18h35", CalculateEndTime(18, 35, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Monday to Friday at 21h35", CalculateEndTime(21, 35, duration), hallsIndex);
	movieIndex--;
	//"The Silence of the Lambs", 118
	duration = 118;
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Saturday, Sunday at 15h35", CalculateEndTime(15, 35, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Saturday, Sunday at 18h00", CalculateEndTime(18, 0, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Saturday, Sunday at 21h25", CalculateEndTime(21, 25, duration), hallsIndex);
	movieIndex--;
	hallsList.AddHall(hallsIndex, &showList.getShowtimeAt(showIndex), &showList.getShowtimeAt(showIndex + 1), &showList.getShowtimeAt(showIndex + 2), &showList.getShowtimeAt(showIndex + 3), &showList.getShowtimeAt(showIndex + 4), &showList.getShowtimeAt(showIndex + 5));
	hallsIndex++;
	showIndex += 6;
	//Hall 7
	//"Saving Private Ryan", 169
	duration = movieList.getMovieAtPosition(movieIndex)->duration;
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Monday to Friday at 15h05", CalculateEndTime(15, 5, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Monday to Friday at 18h25", CalculateEndTime(18, 25, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Monday to Friday at 21h45", CalculateEndTime(21, 45, duration), hallsIndex);
	movieIndex--;
	//"Interstellar", 169
	duration = movieList.getMovieAtPosition(movieIndex)->duration;
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Saturday, Sunday at 15h35", CalculateEndTime(15, 35, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Saturday, Sunday at 18h00", CalculateEndTime(18, 0, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Saturday, Sunday at 21h25", CalculateEndTime(21, 25, duration), hallsIndex);
	movieIndex--;
	hallsList.AddHall(hallsIndex, &showList.getShowtimeAt(showIndex), &showList.getShowtimeAt(showIndex + 1), &showList.getShowtimeAt(showIndex + 2), &showList.getShowtimeAt(showIndex + 3), &showList.getShowtimeAt(showIndex + 4), &showList.getShowtimeAt(showIndex + 5));
	hallsIndex++;
	showIndex += 6;
	//Hall 8
	//"Gladiator", 155
	duration = movieList.getMovieAtPosition(movieIndex)->duration;
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Monday to Friday at 15h15", CalculateEndTime(15, 15, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Monday to Friday at 18h15", CalculateEndTime(18, 15, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Monday to Friday at 21h15", CalculateEndTime(21, 15, duration), hallsIndex);
	movieIndex--;
	//"Joker", 122
	duration = movieList.getMovieAtPosition(movieIndex)->duration;
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Saturday, Sunday at 15h55", CalculateEndTime(15, 55, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Saturday, Sunday at 18h15", CalculateEndTime(18, 15, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Saturday, Sunday at 21h35", CalculateEndTime(21, 35, duration), hallsIndex);
	movieIndex--;
	hallsList.AddHall(hallsIndex, &showList.getShowtimeAt(showIndex), &showList.getShowtimeAt(showIndex + 1), &showList.getShowtimeAt(showIndex + 2), &showList.getShowtimeAt(showIndex + 3), &showList.getShowtimeAt(showIndex + 4), &showList.getShowtimeAt(showIndex + 5));
	hallsIndex++;
	showIndex += 6;
	//Hall 9
	//"The Prestige", 130
	duration = movieList.getMovieAtPosition(movieIndex)->duration;
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Monday to Friday at 15h15", CalculateEndTime(15, 15, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Monday to Friday at 18h15", CalculateEndTime(18, 15, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Monday to Friday at 21h15", CalculateEndTime(21, 15, duration), hallsIndex);
	movieIndex--;
	//"The Usual Suspects", 106
	duration = movieList.getMovieAtPosition(movieIndex)->duration;
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Saturday, Sunday at 15h55", CalculateEndTime(15, 55, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Saturday, Sunday at 18h15", CalculateEndTime(18, 15, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Saturday, Sunday at 21h35", CalculateEndTime(21, 35, duration), hallsIndex);
	movieIndex--;
	hallsList.AddHall(hallsIndex, &showList.getShowtimeAt(showIndex), &showList.getShowtimeAt(showIndex + 1), &showList.getShowtimeAt(showIndex + 2), &showList.getShowtimeAt(showIndex + 3), &showList.getShowtimeAt(showIndex + 4), &showList.getShowtimeAt(showIndex + 5));
	hallsIndex++;
	showIndex += 6;
	//Hall 10
	//"Back to the Future", 116,
	duration = movieList.getMovieAtPosition(movieIndex)->duration;
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Monday to Friday at 15h25", CalculateEndTime(15, 25, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Monday to Friday at 18h25", CalculateEndTime(18, 25, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Monday to Friday at 21h25", CalculateEndTime(21, 25, duration), hallsIndex);
	movieIndex--;
	//"The Lion King", 88
	duration = movieList.getMovieAtPosition(movieIndex)->duration;
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Saturday, Sunday at 15h55", CalculateEndTime(15, 55, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Saturday, Sunday at 18h15", CalculateEndTime(18, 15, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Saturday, Sunday at 21h35", CalculateEndTime(21, 35, duration), hallsIndex);
	movieIndex--;
	hallsList.AddHall(hallsIndex, &showList.getShowtimeAt(showIndex), &showList.getShowtimeAt(showIndex + 1), &showList.getShowtimeAt(showIndex + 2), &showList.getShowtimeAt(showIndex + 3), &showList.getShowtimeAt(showIndex + 4), &showList.getShowtimeAt(showIndex + 5));
	hallsIndex++;
	showIndex += 6;
	//Hall 11
	//"Goodfellas", 146
	duration = movieList.getMovieAtPosition(movieIndex)->duration;
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Monday to Friday at 15h25", CalculateEndTime(15, 25, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Monday to Friday at 18h25", CalculateEndTime(18, 25, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Monday to Friday at 21h25", CalculateEndTime(21, 25, duration), hallsIndex);
	movieIndex--;
	//"Se7en", 127
	duration = movieList.getMovieAtPosition(movieIndex)->duration;
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Saturday, Sunday at 15h55", CalculateEndTime(15, 55, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Saturday, Sunday at 18h15", CalculateEndTime(18, 15, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Saturday, Sunday at 21h35", CalculateEndTime(21, 35, duration), hallsIndex);
	movieIndex--;
	hallsList.AddHall(hallsIndex, &showList.getShowtimeAt(showIndex), &showList.getShowtimeAt(showIndex + 1), &showList.getShowtimeAt(showIndex + 2), &showList.getShowtimeAt(showIndex + 3), &showList.getShowtimeAt(showIndex + 4), &showList.getShowtimeAt(showIndex + 5));
	hallsIndex++;
	showIndex += 6;
	//Hall 12
	//"The Green Mile", 189
	duration = movieList.getMovieAtPosition(movieIndex)->duration;
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Monday to Friday at 14h25", CalculateEndTime(14, 25, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Monday to Friday at 18h00", CalculateEndTime(18, 00, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Monday to Friday at 21h25", CalculateEndTime(21, 25, duration), hallsIndex);
	movieIndex--;
	//"Leon: The Professional", 110
	duration = movieList.getMovieAtPosition(movieIndex)->duration;
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Saturday, Sunday at 15h55", CalculateEndTime(15, 55, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Saturday, Sunday at 18h15", CalculateEndTime(18, 15, duration), hallsIndex);
	showList.AddShowtime(movieList.getMovieAtPosition(movieIndex), "Saturday, Sunday at 21h35", CalculateEndTime(21, 35, duration), hallsIndex);
	movieIndex--;
	hallsList.AddHall(hallsIndex, &showList.getShowtimeAt(showIndex), &showList.getShowtimeAt(showIndex + 1), &showList.getShowtimeAt(showIndex + 2), &showList.getShowtimeAt(showIndex + 3), &showList.getShowtimeAt(showIndex + 4), &showList.getShowtimeAt(showIndex + 5));
	hallsIndex++;
	showIndex += 6;
	//Test  hallsList.DisplayHalls();
	//Test movieList.displayMovies();

}

void CinemaReservation::MainMenu()
{
	string userInput;
	std::regex rangeRegex("^[0-4]$"); // regex to match range from 0 to 3
	bool validated;
	Movie* selectedMovie{ nullptr };
	int selectedHall{ 0 };
	Showtime* selectedShow{ nullptr };
	int nbrTickets{ 0 };
	// ask user for input and validate with regex
	do {

		do {
			validated = false;
			system("cls");
			cout << "Logged as " << currentUser->getUserName() << endl;
			cout << "----------------------------------------------" << endl;
			cout << "CINEMA RESERVATION" << endl;
			cout << "----------------------------------------------" << endl;
			cout << "1- See movies" << endl;
			cout << "2- Reserve movies" << endl;
			cout << "3- Search cinema halls" << endl;
			cout << "4- Check my reservations" << endl;
			cout << "0- Log out" << endl;
			cout << "----------------------------------------------" << endl;
			cin >> userInput;
			validated = std::regex_match(userInput, rangeRegex);
			if (!validated)
			{
				cout << "Invalid input";
				std::this_thread::sleep_for(2s);
			}
			system("cls");
		} while (!validated);
		if (userInput == "0")
			return;
		else if (userInput == "1") {	//Sorted movies
			/*
			* RECOMMENDED FEATURE --- BROKEN
			Movie* sourceMovie = movieList.getMovieAtPosition(0);
			std::vector<Movie*> recommendedMovies;
			if (currentUser->getAgeClassification() != "M")
				recommendedMovies = movieList.recommendMovies(sourceMovie->title, currentUser->preferredGenre, currentUser->getAgeClassification(), currentUser->preferredDirector, currentUser->preferredActor, 4);
			else
				recommendedMovies = movieList.recommendMoviesByAge(sourceMovie->title,currentUser->getAgeClassification(),4);
			movieList.displayRecommended(recommendedMovies);
			system("pause");		}
			*/
			int input = 0;
			movieList.displayMovies();
			do {
				do {
					cout << "0- Back" << endl;
					cout << "1- Sort by title" << endl;
					cout << "2- Sort by duration" << endl;
					cout << "3- Sort by classification" << endl;
					cout << "4- Sort by recommended" << endl;
					cin >> input;
				} while (cin.fail() || input < 0 || input > 4);
				system("cls");
				switch (input)
				{
				case 1 :
					movieList.displayMoviesSortedBy(SortProperty::Title);
					break;
				case 2:
					movieList.displayMoviesSortedBy(SortProperty::Duration);
					break;
				case 3:
					movieList.displayMoviesSortedBy(SortProperty::Classification);
					break;
				case 4:
					//Bugged currently
				default:
					break;
				}
			} while (input != 0);
		}
		else if (userInput == "2")
		{
			selectedMovie = SearchMovieMenu();
			validated = (selectedMovie != nullptr);
			if (validated)
				selectedShow = ChooseShowtime(selectedMovie->title);
			else continue;
		}
		else if (userInput == "3")
		{
			selectedHall = SearchHallsMenu();
			validated = (selectedHall != 0);
			if (validated)
				selectedShow = ChooseShowtime(selectedHall);
			else continue;
		}
		else if (userInput == "4")
		{
			//DisplayReservations
			system("cls");
			this->currentUser->DisplayTickets();
			system("pause");
			continue;
		}
		validated = (selectedShow != nullptr);
		if (validated)
			nbrTickets = ReserveTickets(selectedShow);
		else continue;
		validated = (nbrTickets > 0);
		if (validated)
		{
			AddTicket(selectedShow, nbrTickets);
			system("cls");
			cout << "You reserved " << nbrTickets << " ticket(s) for the movie:" << endl;
			cout << selectedShow->movie->title << endl;
			cout << "on " << selectedShow->startTime << endl;
			cout << "----------------------------------------------" << endl;
			cout << "Thank you for your purchase!!" << endl;
			system("pause>0");
		}
		else continue;
	} while (userInput != "0");
	return;
}

Movie* CinemaReservation::SearchMovieMenu()
{
	int size = movieList.getLength();
	int input;

	do {
		system("cls");
		for (int i = 1; i < size + 1; i++)
			cout << i << "- " << movieList.getMovieAtPosition(size - i)->title << endl;
		cout << "----------------------------------------------" << endl;
		cout << "0- Return to previous menu" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "-Please choose a movie you wish to reserve tickets for-" << endl;
		cin >> input;
	} while (cin.fail() || input < 0 || input > size);
	if (input == 0)
		return nullptr;
	return movieList.getMovieAtPosition(size - input);
}
int CinemaReservation::SearchHallsMenu()
{
	int size = hallsList.GetSize();
	int input;

	do {
		system("cls");
		hallsList.DisplayHalls();
		cout << "-Please choose a Hall you wish to reserve tickets for-" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "0- Return to previous menu" << endl;
		cin >> input;
	} while (cin.fail() || input < 0 || input > size);
	return input;
}
Showtime* CinemaReservation::ChooseShowtime(string movieTitle)
{
	Showtime* show1{ nullptr };
	Showtime* show2{ nullptr };
	Showtime* show3{ nullptr };
	Showtime* selectedShow{ nullptr };
	int index{ 0 };
	for (int i = 0; i < showList.getSize(); i++)
	{
		if (showList.getShowtimeAt(i).movie->title == movieTitle)
		{
			if (index == 0)
			{
				show1 = &showList.getShowtimeAt(i);
				index++;
			}
			else if (index == 1)
			{
				show2 = &showList.getShowtimeAt(i);
				index++;
			}
			else if (index == 2)
				show3 = &showList.getShowtimeAt(i);
		}
	}
	if (show1 == nullptr)
		return nullptr;
	int input;
	do {
		system("cls");
		cout << "Please choose a showtime to reserve tickets" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "Selected movie: " << movieTitle << endl;
		cout << "----------------------------------------------" << endl;
		cout << "1- " << show1->startTime << endl;
		cout << "2- " << show2->startTime << endl;
		cout << "3- " << show3->startTime << endl;
		cout << "----------------------------------------------" << endl;
		cout << "0- " << "Return to previous menu" << endl;
		cin >> input;
	} while (cin.fail() || input < 0 || input > 3);
	if (input == 0)
		return nullptr;
	if (input == 1)
		selectedShow = show1;
	else if (input == 2)
		selectedShow = show2;
	else if (input == 3)
		selectedShow == show3;
	return selectedShow;
}
Showtime* CinemaReservation::ChooseShowtime(int hallNumber) {
	CinemaHall* chosenHall = hallsList.GetHall(hallNumber);
	int input;
	do {
		system("cls");
		cout << "Please choose a showtime to reserve tickets" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "Movie: " << chosenHall->showtime1->movie->title << endl;
		cout << "1- " << chosenHall->showtime1->startTime << endl;
		cout << "2- " << chosenHall->showtime2->startTime << endl;
		cout << "3- " << chosenHall->showtime3->startTime << endl;
		cout << "----------------------------------------------" << endl;
		cout << "Movie: " << chosenHall->showtime4->movie->title << endl;
		cout << "4- " << chosenHall->showtime4->startTime << endl;
		cout << "5- " << chosenHall->showtime5->startTime << endl;
		cout << "6- " << chosenHall->showtime6->startTime << endl;
		cout << "----------------------------------------------" << endl;
		cout << "0- " << "Return to previous menu" << endl;
		cin >> input;
	} while (cin.fail() || input < 0 || input > 6);
	if (input == 1)
		return chosenHall->showtime1;
	if (input == 2)
		return chosenHall->showtime2;
	if (input == 3)
		return chosenHall->showtime3;
	if (input == 4)
		return chosenHall->showtime4;
	if (input == 5)
		return chosenHall->showtime5;
	if (input == 6)
		return chosenHall->showtime6;
	return nullptr;
}
void CinemaReservation::ExitApp()
{
	system("cls");
	cout << "THANK YOU FOR USING OUR CINEMA TICKET APP!!" << endl;
	cout << "Developed by:\nOlivier Grenier\nDominic Audet" << endl;
	system("pause>0");
	exit(EXIT_SUCCESS);
}

//Set the current user after successful login
void CinemaReservation::SetCurrentUser(User* user)
{
	this->currentUser = user;
	this->MainMenu();
}

//Create a new USER
void CinemaReservation::AddUser(std::string userName)
{
	string firstName, lastName, ageClass;
	int age{ 0 };
	cout << "         NEW USER          \n";
	cout << "---------------------------\n";
	cout << "Enter your first name: ";
	while (!(cin >> firstName) || firstName.empty()) {
		cout << "INVALID INPUT\n";
		cout << "Enter your first name: ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	cout << "Enter your last name: ";
	while (!(cin >> lastName) || lastName.empty()) {
		cout << "INVALID INPUT\n";
		cout << "Enter your last name: ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	cout << "How old are you?: ";
	while (!(cin >> age) || age <= 0) {
		cout << "INVALID INPUT\n";
		cout << "How old are you?: ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	if (age < 8)
		ageClass = "G";
	else if (age < 13)
		ageClass = "PG";
	else if (age < 16)
		ageClass = "PG-13";
	else if (age < 18)
		ageClass = "R";
	else
		ageClass = "M";

	User* newUser = new User(userName, firstName, lastName, ageClass);

	//Preferences
	string inputString;
	system("cls");
	cout << "        Preferences        \n";
	cout << "---------------------------\n";
	cin.ignore();
	cout << "What is your favorite genre?: ";
	std::getline(cin, inputString);
	newUser->preferredGenre = MiscMethods::to_upper(inputString);
	cout << endl << "Who is your favorite director?: ";
	std::getline(cin, inputString);
	newUser->preferredDirector = MiscMethods::to_upper(inputString);
	cout << endl << "Who is your favorite actor?: ";
	std::getline(cin, inputString);
	newUser->preferredActor = MiscMethods::to_upper(inputString);

	this->SetCurrentUser(newUser);
	this->userList.push_back(newUser);
	this->MainMenu();
}

string CinemaReservation::CalculateEndTime(int hours, int minutes, int minsToAdd)
{
	string mins, hrs;
	minutes += minsToAdd;
	hours += minutes / 60;
	minutes %= 60;
	hours %= 24;
	hrs = std::to_string(hours);
	if (minutes < 10)
		mins = "0" + std::to_string(minutes);
	else mins = std::to_string(minutes);
	string time = hrs + "h" + mins;
	return time;
}
int CinemaReservation::ReserveTickets(Showtime* showtime)
{
	int maxAmount = showtime->seatingCapacity - showtime->currentSeats;
	int input;
	do {
		system("cls");
		cout << "Movie: " << showtime->movie->title << endl;
		cout << "----------------------------------------------" << endl;
		cout << "Starts " << showtime->startTime << endl;
		cout << "Ends at                    " << showtime->endTime << endl;
		cout << "----------------------------------------------" << endl;
		cout << "How many tickets do you want to reserve? (seats available: " << maxAmount << ")" << endl;
		cin >> input;
	} while (cin.fail() || input > maxAmount);
	return input;
}
void CinemaReservation::AddTicket(Showtime* showtime, int amount)
{
	TicketReservation newticketreq = TicketReservation(showtime->cinemaHall, showtime->startTime, amount, this->currentUser->getUserName());
	this->ticketReservationRequests.push(newticketreq);
	for (int i = 0; i < amount; i++) {
		this->currentUser->AddPurchasedTickets(showtime->movie, showtime->startTime, showtime->cinemaHall);
		showtime->currentSeats++;
	}
}