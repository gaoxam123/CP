#include <bits/stdc++.h>
#include "Movie.h"
using namespace std;

Movie::Movie(string name, string rating, int watched) : name{name}, rating{rating}, watched{watched} {}

Movie::Movie(const Movie &source) : Movie{source.name, source.rating, source.watched} {}

Movie::~Movie() {}

void Movie::display() const {
    cout << this->name << " " << this->rating << " " << this->watched << endl;
}