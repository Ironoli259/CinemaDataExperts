#pragma once
#include <unordered_map>
#include <string>

struct Movie;

class MovieGraph
{
public:
	MovieGraph() = default;
	void addMovie(const Movie* movie);
	void addEdge(const Movie* movie1, const Movie* movie2);
	void removeMovie(const Movie* movie);
	float calculateSimilarity(const Movie* movie, const std::string& genre, const std::string& classification, const std::string& director, const std::string& actor) const;
	std::vector<Movie*> recommendMovies(const Movie*source, const std::string& genre, const std::string& classification, const std::string& director, const std::string& actor, int maxDepth = 3) const;

private:
	std::unordered_map<const Movie*, std::vector<const Movie*>> adjacencyList;
};

