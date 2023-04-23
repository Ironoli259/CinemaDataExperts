#pragma once
#include "MovieList.h"
#include "ArrayCustom.h"
#include "ArrayCustom.cpp"

// Showtime Structure
struct Showtime {

	Movie* movie;
	std::string startTime;
	std::string endTime;
	int cinemaHall;

	Showtime() : movie(nullptr), startTime(""), endTime(""), cinemaHall(0) {}
	Showtime(Movie* movie, const std::string& startTime, const std::string& endTime,const int cinemaHall) :
		movie(movie), startTime(startTime), endTime(endTime), cinemaHall(cinemaHall) {}
};


class ShowtimeList {
private:
	static const int MAX_SIZE = 100;
	ArrayCustom<Showtime> showtimes;
	int size;

public:
	ShowtimeList();
	~ShowtimeList();
	void AddShowtime(Movie* movie, const std::string& startTime, const std::string& endTime, const int cinemaHall);
	void removeShowtime(int index);
	int getSize() const;
	Showtime& getShowtimeAt(int index);
};
