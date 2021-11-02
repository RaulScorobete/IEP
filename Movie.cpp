//
// Created by raul on 02.11.2021.
//

#include "Movie.h"
#include <string.h>

Movie::Movie() {
    name[0] = '\0';
    year = 0;
    score = 0.0;
}

Movie::Movie(const char *name, int year, float score) {
    strcpy(this->name, name);
    this->year = year;
    this->score = score;
}

const char *Movie::getName(){
    return name;
}

int Movie::getYear(){
    return year;
}

void Movie::setYear(int year) {
    this->year = year;
}

float Movie::getScore(){
    return score;
}

void Movie::setScore(float score) {
    this->score = score;
}

void Movie::setName(const char *name) {
    strcpy(this->name, name);
}

Movie::Movie(const Movie &m) {
    score = m.score;
    year = m.year;
    strcpy(name, m.name);
}
