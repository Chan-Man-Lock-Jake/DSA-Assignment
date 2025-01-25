#pragma once
#include <iostream>
#include <string>
using namespace std;
class Movie
{
public:
    string title;
    int id;
    string plot;
    int yearOfRelease;
    //vector<Actor*> actors; // References to actors in the movie

    Movie(std::string title, std::string plot, int yearOfRelease)
        : title(title), plot(plot), yearOfRelease(yearOfRelease) {}
};

