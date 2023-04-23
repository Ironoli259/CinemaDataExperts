#include <iostream>
#include "MovieList.h"

using namespace std;

// Custom comparator functions for AVLTree
bool compareByTitle(const Movie* movie1, const Movie* movie2) {
	if (movie1 == nullptr || movie2 == nullptr) {
		throw std::invalid_argument("Null pointers are not allowed.");
	}
	return movie1->title < movie2->title;
}

bool compareByDuration(const Movie* movie1, const Movie* movie2) {
	if (movie1 == nullptr || movie2 == nullptr) {
		throw std::invalid_argument("Null pointers are not allowed.");
	}
	return movie1->duration < movie2->duration;
}

bool compareByClassification(const Movie* movie1, const Movie* movie2) {
	if (movie1 == nullptr || movie2 == nullptr) {
		throw std::invalid_argument("Null pointers are not allowed.");
	}
	return movie1->classification < movie2->classification;
}

MovieList::MovieList() : head(nullptr),titleTree(compareByTitle), durationTree(compareByDuration), classificationTree(compareByClassification), size(0) {
}

MovieList::~MovieList() {
	clearList();
}

//Add Movie method. Insert at end.
void MovieList::addMovie(const std::string& title, int duration, const std::string& classification, const std::string& synopsis, const std::string& genre, const std::string& director, const std::string& actor) {
	Movie* newMovie = new Movie{ title, duration, classification, synopsis, genre, director, actor, 0 };
	newMovie->next = head;
	head = newMovie;
	titleTree.insert(newMovie);
	durationTree.insert(newMovie);
	classificationTree.insert(newMovie);
	movieGraph.addMovie(newMovie);
	size++;
}

//Remove Movie method.
void MovieList::removeMovie(const std::string& title) {
	Movie temp(title, 0, "", "", "", "", "", 0);
	Movie* movieToRemove = titleTree.search(&temp);
	if (movieToRemove == nullptr) {
		cout << "Movie not found.\n";
		return;
	}
	titleTree.remove(movieToRemove);
	durationTree.remove(movieToRemove);
	classificationTree.remove(movieToRemove);

	//Remove from linked list
	Movie* prev = nullptr;
	Movie* curr = head;
	while (curr != nullptr && curr != movieToRemove) {
		prev = curr;
		curr = curr->next;
	}

	if (prev == nullptr)
		head = head->next;
	else
		prev->next = curr->next;
	
	delete movieToRemove;
	size--;
}

bool printMovieInfo(const Movie& movie) {
	cout << "Title: " << movie.title << endl;
	cout << "Duration: " << movie.duration << " minutes" << endl;
	cout << "Classification: " << movie.classification << endl;
	cout << "Synopsis: " << movie.synopsis << endl;
	cout << "Genre: " << movie.genre << endl;
	cout << "Director: " << movie.director << endl;
	cout << "Actor: " << movie.actor << endl;
	cout << "--------------------------------------" << endl;

	// Return true to continue traversing the tree
	return true;
}

//Display all movies
void MovieList::displayMovies() {
	if (head == nullptr) {
		cout << "There are no movies to display.\n";
		return;
	}

	Movie* temp = head;
	while (temp != nullptr) {
		printMovieInfo(*temp);
		temp = temp->next;
	}

}

//Get the length of the list
int MovieList::getLength() {
	Movie* temp = head;
	int count = 0;
	while (temp != nullptr) {
		temp = temp->next;
		count++;
	}
	return count;
}

//Clear the list
void MovieList::clearList() {
	Movie* temp = head;
	while (temp != nullptr) {
		Movie* next = temp->next;
		delete temp;
		temp = next;
	}
	head = NULL;
}

int getClassificationPriority(const std::string& classification) {
	if (classification == "G") return 0;
	if (classification == "PG") return 1;
	if (classification == "PG-13") return 2;
	if (classification == "R") return 3;
	if (classification == "M") return 4;
	return -1;
}

//Returns the pointer of the movie in a specified position
Movie* MovieList::getMovieAtPosition(int position) {
	if (position < 0) { throw invalid_argument("Position must be non-negative."); }

	Movie* temp = head;
	int count = 0;
	while (temp != NULL && count < position) {
		temp = temp->next;
		count++;
	}
	if (count < position || temp == NULL) { throw out_of_range("Position is out of bounds."); }
	return temp;
}

Movie* MovieList::getMovieByTitle(const std::string& title) const
{
	Movie* currentMovie = head;

	while (currentMovie != nullptr) {
		if (currentMovie->title == title) {
			return currentMovie;
		}
		currentMovie = currentMovie->next;
	}
	return nullptr;	//movie not found
}

void MovieList::addMovieRelationship(const std::string& title1, const std::string& title2)
{
	Movie* movie1 = getMovieByTitle(title1);
	Movie* movie2 = getMovieByTitle(title2);

	if (movie1 && movie2)
		movieGraph.addEdge(movie1, movie2);
}

//Recommendation System
vector<Movie*> MovieList::recommendMovies(const std::string& title, const string& genre, const string& classification, const string& director, const string& actor, int maxDepth) const
{
	Movie* sourceMovie = getMovieByTitle(title);

	if (sourceMovie) {
		return movieGraph.recommendMovies(sourceMovie, genre, classification, director, actor, maxDepth);
	}
	else {
		return std::vector<Movie*>{}; // Return an empty vector if the movie is not found
	}
}

vector<Movie*> MovieList::recommendMoviesByAge(const std::string& title, const std::string& preferredClassification, int maxDepth) const {
	Movie* sourceMovie = getMovieByTitle(title);

	if (!sourceMovie) {
		return std::vector<Movie*>{}; // Return an empty vector if the movie is not found
	}

	// Get the recommended movies without any filter
	auto movies = movieGraph.recommendMovies(sourceMovie, "", "", "", "", maxDepth);

	// Filter out movies that are above the user's preferred classification
	int userClassificationPriority = getClassificationPriority(preferredClassification);
	auto it = std::remove_if(movies.begin(), movies.end(), [&](const Movie* movie) {
		return getClassificationPriority(movie->classification) > userClassificationPriority;
		});
	movies.erase(it, movies.end());

	// Sort the recommended movies by classification priority
	std::sort(movies.begin(), movies.end(), [&](const Movie* a, const Movie* b) {
		return getClassificationPriority(a->classification) < getClassificationPriority(b->classification);
		});

	return movies;
}

void MovieList::displayMoviesSortedBy(SortProperty option) {
	if (titleTree.isEmpty()) {
		cout << "There are no movies to display.\n";
		return;
	}

	cout << "Movies sorted by ";

	switch (option) {
	case SortProperty::Title:
		cout << "title:\n";
		titleTree.traverseInOrdermain([](const Movie* movie) {
			return printMovieInfo(*movie);
			});
		break;
	case SortProperty::Duration:
		cout << "duration:\n";
		durationTree.traverseInOrdermain([](const Movie* movie) {
			return printMovieInfo(*movie);
			});
		break;
	case SortProperty::Classification:
		cout << "classification:\n";
		classificationTree.traverseInOrdermain([](const Movie* movie) {
			return printMovieInfo(*movie);
			});
		break;
	default:
		cout << "Invalid sort option.\n";
	}
}

void MovieList::displayRecommended(vector<Movie*> movies)
{
	cout << "RECOMMENDED MOVIES\n";
	cout << "---------------------------------------\n";
	for (const auto& movie : movies) {
		cout << "-> " + movie->title << endl;
	}
}