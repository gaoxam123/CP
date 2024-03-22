#ifndef _MOVIE_H_
#define _MOVIE_H_
//#include "Movies.h"
#include <bits/stdc++.h>
using namespace std;

class Movie {
private:
    string name;
    string rating;
    int watched; 

public:
    Movie(string name = "None", string rating = "None", int watched = 0);
    Movie(const Movie &source);
    ~Movie();
    string get_name() const {return name;}
    string get_rating() const {return rating;}
    int get_watched() const {return watched;}
    void set_name(string name) {this->name = name;}
    void set_rating(string rating) {this->rating = rating;}
    void set_watched(int watched) {this->watched = watched;}
    void incremented_watched() {++watched;}
    void display() const;
};

#endif