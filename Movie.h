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

    Movie& operator=(const Movie& other);

    void copy(const Movie& other);

    const char *getName();

    int getYear();

    float getScore();

    void setName(const char* name);

    void setYear(int year);

    void setScore(float score);
};


#endif //IEP_MOVIE_H
