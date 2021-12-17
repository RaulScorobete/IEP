//
// Created by raul on 02.11.2021.
//

#ifndef IEP_MOVIESERIES_H
#define IEP_MOVIESERIES_H
#include "Movie.h"
#define max_movies 200

class MovieSeries {
private:
    Movie movies[max_movies];
    int size;

public:
    MovieSeries();
    MovieSeries& operator+=(const Movie& movie);
    void addMovie(Movie m);
    void printMovies();
    void sortMoviesByScore();
};


#endif //IEP_MOVIESERIES_H
