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
	std::string trailer; //Not sure whether to keep it a string
	Movie* next;

	Movie(const std::string& title, int duration, const std::string& classification, const std::string& synopsis, const std::string& trailer): title(title), duration(duration), classification(classification), synopsis(synopsis), trailer(trailer), next(nullptr) {}
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
	void addMovie(const std::string& title, int duration, const std::string& classification, const std::string& synopsis, const std::string& trailer);
	void removeMovie(const std::string& title);
	void displayMovies();
	void displayMoviesSortedBy(SortProperty sortProp);
	int getLength();
	void clearList();	
	Movie* getMovieAtPosition(int position);	
};