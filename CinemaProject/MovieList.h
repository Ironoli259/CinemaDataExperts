#pragma once
#include <string>
#include <vector>
#include <functional>
#include "AVLTree.h"
#include "SortProperty.cpp"
#include "MovieGraph.h"
#include "ShowtimeList.h"

using std::vector;

// Move the Movie struct definition outside of the MovieList class
struct Movie {
	std::string title;
	int duration; //minutes
	std::string classification;
	std::string synopsis;
	std::string genre;
	std::string director;
	std::string actor;
	float rating; //out of 10
	Movie* next;
	//Showtime* show1;
	//Showtime* show2;
	//Showtime* show3;
	Movie(const std::string& title, int duration, const std::string& classification, const std::string& synopsis, const std::string& genre, const std::string& director, const std::string& actor, float rating) :
		title(title), duration(duration), classification(classification), synopsis(synopsis), genre(genre), director(director), actor(actor), rating(0), next(nullptr){}
};

class MovieList
{
private:
	Movie* head;
	int size;
	AVLTree<Movie> titleTree;
	AVLTree<Movie> durationTree;
	AVLTree<Movie> classificationTree;
	MovieGraph movieGraph;

public:
	MovieList();
	~MovieList();
	void addMovie(const std::string& title, int duration, const std::string& classification, const std::string& synopsis, const std::string& genre, const std::string& director, const std::string& actor, float rating);
	void removeMovie(const std::string& title);
	void displayMovies();
	void displayMoviesSortedBy(SortProperty sortProp);
	int getLength();
	void clearList();	
	Movie* getMovieAtPosition(int position);	
	Movie* getMovieByTitle(const std::string& title) const;
	void addMovieRelationship(const std::string& title1, const std::string& title2);
	vector<Movie*> recommendMovies(const std::string& title, const std::string& genre, const std::string& classification, const std::string& director, const std::string& actor, int maxDepth) const;
	vector<Movie*> recommendMoviesByAge(const std::string& title, const std::string& preferredClassification, int maxDepth) const;
	void displayRecommended(vector<Movie*> movies);
};