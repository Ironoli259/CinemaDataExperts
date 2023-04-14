#include <iostream>
#include "MovieList.h"

//Main
int main()
{
    MovieList movieList;

    movieList.addMovie("Interstellar", 189, "PG-13", "A team of explorers travel through a wormhole in space in an attempt to ensure humanity's survival.", "temp");
    movieList.addMovie("Avatar", 182, "PG-13", "A paraplegic Marine dispatched to the moon Pandora on a unique mission becomes torn between following his orders and protecting the world he feels is his home.", "temp");
    movieList.addMovie("Ted", 106, "R", "John Bennett, a man whose childhood wish of bringing his teddy bear to life came true, now must decide between keeping the relationship with the bear, Ted or his girlfriend, Lori.", "temp");

    movieList.displayMovies();
    movieList.displayMoviesSortedBy(SortProperty::Title);
    movieList.displayMoviesSortedBy(SortProperty::Duration);
    movieList.displayMoviesSortedBy(SortProperty::Classification);
}