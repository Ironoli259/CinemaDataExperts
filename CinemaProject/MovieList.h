#pragma once
#include <string>
#include <vector>
#include <functional>
#include "AVLTree.h"
#include "SortProperty.cpp"

//Movie Structure

struct Movie {
	std::string title;
	int duration; //minutes
	std::string classification;
	std::string synopsis;
	std::string genre;
	std::string director;
	std::string actor;
	float rating; //out of 5
	Movie* next;

	Movie(const std::string& title, int duration, const std::string& classification, const std::string& synopsis, const std::string& genre, const std::string& director, const std::string& actor, float rating):
		title(title), duration(duration), classification(classification), synopsis(synopsis), genre(genre), director(director), actor(actor), rating(0), next(nullptr) {}
};

class MovieList
{
private:	
	Movie* head;
	int size;
	AVLTree<Movie> titleTree;
	AVLTree<Movie> durationTree;
	AVLTree<Movie> classificationTree;

public:
	MovieList();
	~MovieList();
	void addMovie(const std::string& title, int duration, const std::string& classification, const std::string& synopsis, const std::string& genre, const std::string& director, const std::string& actor);
	void removeMovie(const std::string& title);
	void displayMovies();
	void displayMoviesSortedBy(SortProperty sortProp);
	int getLength();
	void clearList();	
	Movie* getMovieAtPosition(int position);	
};