#pragma once
#include <string>
using namespace std;

class Movie {
public:
    int id;
    string name;
    int yearOfRelease;

    Movie();

    Movie(int id, string name, int yearOfRelease) { 
        this->id = id;
        this->name = name;
        this->yearOfRelease = yearOfRelease;
    }
};
