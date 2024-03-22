#include <bits/stdc++.h>
#include "Movies.h"
using namespace std;

Movies::Movies() {}
Movies::~Movies() {}

bool Movies::add_movie(string name, string rating, int watched) {
    for(const auto &movie: movies) {
        if(movie.get_name() == name) {
            return false;
        }
    }
    Movie tmp{name, rating, watched};
    movies.push_back(tmp);
    return true;
}

bool Movies::increment_watched(string name) {
    for(auto &movie: movies) {
        if(movie.get_name() == name) {
            movie.incremented_watched();
            return true;
        }
    }
    return false;
}

void Movies::display() const {
    if(movies.size() == 0) {
        cout << "no movies to display" << endl;
        return;
    }
    for(const auto &movie: movies) {
        movie.display();
    }
    cout << endl;
}