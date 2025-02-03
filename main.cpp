// DSA_Assg.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "AVLBST.h"
#include "Actor.h"
#include "Movie.h"
using namespace std;
// Function Prototypes
void adminMenu();
void userMenu();

// Global Data Structures
//AVLBST<Actor> actorTree;
//AVLBST<Movie> movieTree;
//HashTable<Actor> actorHashTable(100);  // Assuming 100 as hash table size
//HashTable<Movie> movieHashTable(100);

int main() {
    int choice;

    while (true) {
        cout << "----------------------------------------\n";
        cout << "      Welcome to the Movie App          \n";
        cout << "----------------------------------------\n";
        cout << "1. Administrator Menu\n";
        cout << "2. User Menu\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            adminMenu();
            break;
        case 2:
            userMenu();
            break;
        case 3:
            cout << "Exiting application. Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}

void adminMenu() {
    int choice;
    cout << "\nAdministrator Menu\n";
    cout << "1. Add Actor\n";
    cout << "2. Add Movie\n";
    cout << "3. Add Actor to Movie\n";
    cout << "4. Update Actor/Movie Details\n";
    cout << "5. Back to Main Menu\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1: {
        string name;
        int yearOfBirth;
        int id;
        cout << "Enter actor name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter actor year of birth: ";
        cin >> yearOfBirth;
        cout << "Enter actor id: ";
        cin >> id;
        //Actor* newActor = new Actor(id, name, yearOfBirth);
        //actorTree.insert(newActor);
        //actorHashTable.insert(yearOfBirth, newActor);
        cout << "Actor added successfully.\n";
        break;
    }
    case 2: {
        string title, plot;
        int yearOfRelease;
        cout << "Enter movie title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter movie plot: ";
        getline(cin, plot);
        cout << "Enter movie year of release: ";
        cin >> yearOfRelease;
        //Movie* newMovie = new Movie(title, plot, yearOfRelease);
        //movieTree.insert(newMovie);
        //movieHashTable.insert(yearOfRelease, newMovie);
        cout << "Movie added successfully.\n";
        break;
    }
    case 3: {
        string actorName, movieTitle;
        cout << "Enter actor name: ";
        cin.ignore();
        getline(cin, actorName);
        cout << "Enter movie title: ";
        getline(cin, movieTitle);

        //Actor* actor = actorTree.search(actorName);
        //Movie* movie = movieTree.search(movieTitle);

        //if (actor && movie) {
        //    actor->movies.push_back(movie);
        //    movie->actors.push_back(actor);
        //    cout << "Actor added to the movie successfully.\n";
        //}
        //else {
        //    cout << "Actor or Movie not found.\n";
        //}
        break;
    }
    case 4:
        cout << "Feature under development.\n";
        break;
    case 5:
        return;
    default:
        cout << "Invalid choice. Please try again.\n";
    }
}

void userMenu() {
    int choice;
    cout << "\nUser Menu\n";
    cout << "1. Display Actors by Age Range\n";
    cout << "2. Display Movies Released in the Past 3 Years\n";
    cout << "3. Display Movies of an Actor\n";
    cout << "4. Display Actors in a Movie\n";
    cout << "5. Display Friends of an Actor\n";
    cout << "6. Back to Main Menu\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "Feature under development.\n";
        break;
    case 2:
        cout << "Feature under development.\n";
        break;
    case 3:
        cout << "Feature under development.\n";
        break;
    case 4:
        cout << "Feature under development.\n";
        break;
    case 5:
        cout << "Feature under development.\n";
        break;
    case 6:
        return;
    default:
        cout << "Invalid choice. Please try again.\n";
    }
}