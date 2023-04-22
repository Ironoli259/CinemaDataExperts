#include "ShowtimeList.h"
#include <stdexcept>
using std::string;

// ShowtimeList constructor
ShowtimeList::ShowtimeList() : size(0) {}

// ShowtimeList destructor
ShowtimeList::~ShowtimeList() {}

// Add a new showtime to the list
void ShowtimeList::addShowtime(Movie* movie, const string& startTime, const string& endTime,const int cinemaHall) {
    if (size >= MAX_SIZE) {
        throw std::out_of_range("ShowtimeList is full");
    }
    showtimes[size] = Showtime(movie, startTime, endTime, cinemaHall);
    size++;
}

// Remove a showtime from the list at the given index
void ShowtimeList::removeShowtime(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    for (int i = index; i < size - 1; i++) {
        showtimes[i] = showtimes[i + 1];
    }
    size--;
}

// Get the number of showtimes in the list
int ShowtimeList::getSize() const {
    return size;
}

// Get a pointer to the showtime at the given index
Showtime* ShowtimeList::getShowtimeAt(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return &showtimes[index];
}
