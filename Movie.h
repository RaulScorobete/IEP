//
// Created by raul on 02.11.2021.
//

#ifndef IEP_MOVIE_H
#define IEP_MOVIE_H


class Movie {
private:
    char name[100];
    int year;
    float score;

public:
    Movie();
    Movie(const char* name,int year,float score);
    Movie(const Movie &m);

    const char *getName();

    int getYear();

    void setYear(int year);

    float getScore();

    void setScore(float score);

    void setName(const char* name);
};


#endif //IEP_MOVIE_H
