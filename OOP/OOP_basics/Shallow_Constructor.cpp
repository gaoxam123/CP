#include <bits/stdc++.h>
using namespace std;

class Shallow {
private:
    int *data;

public:
    Shallow(int d);
    Shallow(const Shallow &source);
    ~Shallow();
};

Shallow::Shallow(int d) {
    data = new int;
    *data = d;
}

Shallow::~Shallow() {
    delete data;
}

Shallow::Shallow(const Shallow &source) : data(source.data) {
    
}