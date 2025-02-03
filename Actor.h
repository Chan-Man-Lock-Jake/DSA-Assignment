#pragma once
#include <string>
using namespace std;

class Actor {
public:
    int id;
    string name;
    int yearOfBirth;

    Actor();

    Actor(int id, string name, int yearOfBirth) {
        this->id = id;
        this->name = name;
        this->yearOfBirth = yearOfBirth;
    }
};
