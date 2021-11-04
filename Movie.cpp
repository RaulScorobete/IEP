//
// Created by raul on 02.11.2021.
//

#include "Movie.h"
#include <string.h>

Movie::Movie() : year(0), score(0.0) {
    name[0] = '\0';
}

Movie::Movie(const char *name, int year, float score) : year(year), score(score) {
    strcpy(this->name, name);
}

Movie::Movie(const Movie &m) : year(m.year), score(m.score) {
    strcpy(name, m.name);
}

const char *Movie::getName() {
    return name;
}

int Movie::getYear() {
    return year;
}

float Movie::getScore() {
    return score;
}

void Movie::setName(const char *name) {
    strcpy(this->name, name);
}

void Movie::setYear(int year) {
    this->year = year;
}

void Movie::setScore(float score) {
    this->score = score;
}


