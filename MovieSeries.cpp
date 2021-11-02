//
// Created by raul on 02.11.2021.
//

#include "MovieSeries.h"
#include <iostream>

MovieSeries::MovieSeries() {
    size = 0;
}

void MovieSeries::addMovie(Movie m) {
    if (size != max_movies) {
        movies[size] = m;
        size++;
    }
}

void MovieSeries::printMovies() {
    int i;
    for (i = 0; i < size; i++) {
        std::cout << "Name: " << movies[i].getName() << " | Rating: " << movies[i].getScore() << " | Release year: "
                  << movies[i].getYear() << "\n";
    }
    std::cout << "--------------------------------------------------------" << "\n";
}

void MovieSeries::sortMoviesByScore() {
    int i, j;
    Movie aux;
    for (i = 0; i < size - 1; i++)
        for (j = i + 1; j < size; j++)
            if (movies[i].getScore() < movies[j].getScore()) {
                aux = movies[i];
                movies[i] = movies[j];
                movies[j] = aux;
            }

}
