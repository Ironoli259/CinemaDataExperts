#include "MovieList.h"
#include "MovieGraph.h"
#include <queue>
#include <unordered_set>

void MovieGraph::addMovie(const Movie* movie) {
	adjacencyList[movie] = std::vector<const Movie*>{};
}

void MovieGraph::addEdge(const Movie* movie1, const Movie* movie2) {
	adjacencyList[movie1].emplace_back(movie2);
	adjacencyList[movie2].emplace_back(movie1);
}

float MovieGraph::calculateSimilarity(const Movie* movie, const std::string& genre, const std::string& classification, const std::string& director, const std::string& actor) const {
	float score = 0;

	if (movie->genre == genre) score += 1.0;
	if (movie->classification == classification) score += 1.0;
	if (movie->director == director) score += 1.0;
	if (movie->actor == actor) score += 1.0;

	return score;
}


std::vector<Movie*> MovieGraph::recommendMovies(const Movie* source, const std::string& genre, const std::string& classification, const std::string& director, const std::string& actor, int maxDepth) const {
	std::vector<Movie*> recommendedMovies;
	std::queue<std::pair<const Movie*, int>> bfsQueue;	//Breadth-First Search. Graph searching algorithm. Indian tutorials are the best!
	std::unordered_set<const Movie*> visited;

	bfsQueue.push(std::make_pair(source,0 ));
	visited.insert(source);

	while (!bfsQueue.empty()) {
		//Get the front element and its depthe from the bfsQueue
		std::pair<const Movie*, int> frontElement = bfsQueue.front();
		bfsQueue.pop();

		const Movie* currentMovie = frontElement.first;
		int depth = frontElement.second;

		if (depth >= maxDepth)
			continue;

		//Enque unvisited neighbors of currentMovie into bfsQueue
		for (const auto& neighbor : adjacencyList.at(currentMovie)) {
			if (visited.find(neighbor) == visited.end()) {
				bfsQueue.push(std::make_pair(neighbor, depth + 1));
				visited.insert(neighbor);
			}
		}
	}

	// Calculate similarity scores for each movie and store them in a vector of pairs
	std::vector<std::pair<const Movie*, float>> scoredMovies;
	for (const auto& movie : visited) {
		if (movie != source) {
			float similarityScore = calculateSimilarity(movie, genre, classification, director, actor);
			scoredMovies.emplace_back(movie, similarityScore);
		}
	}

	//Sort the movies based on their similarity scores
	std::sort(scoredMovies.begin(), scoredMovies.end(), [](const std::pair<const Movie*, float>& a, const std::pair<const Movie*, float>& b) {
		return a.second > b.second;
		});

	//Convert the sorted scoredMovies vector to a vector of Movie pointers	
	for (const auto& scoredMovie : scoredMovies) {
		recommendedMovies.push_back(const_cast<Movie*>(scoredMovie.first));
	}

	return recommendedMovies;
}