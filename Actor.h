#pragma once
#include <iostream>
#include <string>
using namespace std;
class Actor
{
public:
    string name;
    int id;
    int yearOfBirth;
    //vector<Movie*> movies; // References to movies the actor is in
    //vector<Actor*> friends; // References to known actors (friend list)

    Actor(std::string name, int yearOfBirth)
        : name(name), yearOfBirth(yearOfBirth) {}
};