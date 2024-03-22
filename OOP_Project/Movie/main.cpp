#include <bits/stdc++.h>
#include "Movies.h"
using namespace std;

void increment_watched(Movies &movies, string name);
void add_movie(Movies &movies, string name, string rating, int watched);

void increment_watched(Movies &movies, string name) {
    if(movies.increment_watched(name)) {
        cout << name << "watched incremented" << endl;
    }
    else {
        cout << name << "not found" << endl;
    }
}

void add_movie(Movies &movies, string name, string rating, int watched) {
    if(movies.add_movie(name, rating, watched)) {
        cout << name << "added" << endl;
    }
    else {
        cout << name << "already exists" << endl;
    }
}

int main() {
    Movies my_movies;
    
    my_movies.display();
    
    add_movie(my_movies, "Big", "PG-13",2);                 // OK
    add_movie(my_movies,"Star Wars", "PG",5);             // OK
    add_movie(my_movies,"Cinderella", "PG",7);           // OK
     
    my_movies.display();   // Big, Star Wars, Cinderella
    
    add_movie(my_movies,"Cinderella", "PG",7);            // Already exists
    add_movie(my_movies,"Ice Age", "PG",12);              // OK
 
    my_movies.display();    // Big, Star Wars, Cinderella, Ice Age
    
    increment_watched(my_movies,"Big");                    // OK
    increment_watched(my_movies,"Ice Age");              // OK
    
    my_movies.display();    // Big and Ice Age watched count incremented by 1
    
    increment_watched(my_movies,"XXX");         // XXX not found

	return 0;
}