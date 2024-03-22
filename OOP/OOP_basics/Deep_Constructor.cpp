#include <bits/stdc++.h>
using namespace std;

class Deep {
private:
    int *data;

public:
    int get_data_value() {return *data;}
    Deep(int d);
    Deep(const Deep &source);
    ~Deep();
};

Deep::Deep(int d) {
    data = new int;
    *data = d;
}

Deep::~Deep() {
    delete data;
}

Deep::Deep(const Deep &source) {
    data = new int;
    *data = *source.data;
    cout << "Copy Constructor - deep" << endl;
}

// delegating

Deep::Deep(const Deep &source) : Deep{*source.data} {

}

void display(Deep s) {
    cout << s.get_data_value() << endl;
}