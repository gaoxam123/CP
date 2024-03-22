#ifndef _MOVIES_H_
#define _MOVIES_H_
#include <bits/stdc++.h>
#include "Movie.h"
using namespace std;

class Movies {
private:
    vector <Movie> movies;
public:
    Movies();
    ~Movies();
    void display() const;
    bool increment_watched(string name);
    bool add_movie(string name, string rating, int watched);
};

#endif