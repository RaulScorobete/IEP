#include <iostream>
#include "Movie.h"
#include "MovieSeries.h"

int main()
{
    MovieSeries series;
    Movie movie1("Avengers",2012,7.5);
    Movie movie2("Avengers2",2016,7.3);
    Movie movie3("Avengers3",2018,8.5);
    Movie movie4("Avengers4",2019,8.2);
    series.addMovie(movie1);
    series.addMovie(movie2);
    series.addMovie(movie3);
    series.addMovie(movie4);
    movie4.setName("Avengers Endgame");
    series.addMovie(movie4);
    series.printMovies();
    series.sortMoviesByScore();
    series.printMovies();

}