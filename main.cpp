#include <iostream>
#include "Movie.h"
#include "MovieSeries.h"
#include <mutex>
#include <thread>
#include <memory>
#include <fstream>
#include <string>

#define SERIES_SIZE 100

struct Context {
    MovieSeries series[SERIES_SIZE];
    int size;
    std::mutex mutex;
    Context();
};

MovieSeries parseFile(const char* file) {
    std::ifstream f(file);
    std::unique_ptr<char[]> ptr(new char[10000]);
    MovieSeries readSeries;
    while (!f.eof())
    {
        f.getline(ptr.get(),10000);
        Movie movie;
        int i;
        int sizeptr = strlen(ptr.get());
        for (i = 0; i < sizeptr; i++)
        {
            if (ptr[i] == ',')
            {
                ptr[i] = '\0';
                movie.setName(ptr.get());
                break;
            }
        }

        int j = i;
        for (;i < sizeptr; i++)
        {
            if (ptr[i] == ',')
            {
                ptr[i] = '\0';
                int year=std::stoi(&ptr[j + 1]);
                movie.setYear(year);
                break;
            }
        }

        float score = std::stof(&ptr[i + 1]);
        movie.setScore(score);

        readSeries.addMovie(movie);
    }
    return readSeries;
}

void ThreadFunction(std::shared_ptr<Context> context, const char* file) {
    MovieSeries x = parseFile(file);
    context->mutex.lock();
    context->series[context->size] = x;
    context->size++;
    context->mutex.unlock();
}

int main()
{
    std::shared_ptr<Context> context(new Context);
    const char* files[] = { "C:/Users/rault/Documents/Visual Studio 2019/Projects/iep/data/Data1.txt","C:/Users/rault/Documents/Visual Studio 2019/Projects/iep/data/Data2.txt" };
    for (int i=0;i<2;i++)
    {
        ThreadFunction(context, files[i]);
    }

    for (int i = 0; i < context->size; i++)
    {
        context->series[i].printMovies();
    }
    //MovieSeries series;
    //Movie movie1("Avengers",2012,7.5);
    //Movie movie2("Avengers2",2016,7.3);
    //Movie movie3("Avengers3",2018,8.5);
    //Movie movie4("Avengers4",2019,8.2);
    //series.addMovie(movie1);
    //series+=movie2;
    //series.addMovie(movie3);
    //series+=movie4;
    //movie4.setName("Avengers Endgame");
    //series.addMovie(movie4);
    //series.printMovies();
    //series.sortMoviesByScore();
    //series.printMovies();

}

Context::Context()
{
    size = 0;
}
