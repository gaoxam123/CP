#include <bits/stdc++.h>
using namespace std;

class Move{
private:
    int *data;

public:
    void set_value(int d) {*data = d;}
    int get_value() {return *data;}
    Move(int d);
    Move(const Move &source);
    Move(Move &&source) noexcept;
    ~Move();
};

Move::Move(int d) {
    data = new int;
    *data = d;
    cout << "Constructor for " << d << endl;
}

Move::~Move() {
    if(data != nullptr) {
        cout << "Destructor freeing data for" << *data << endl;
    }
    else {
        cout << "Destructor freeing data for nullptr" << endl;
    }
    delete data;
}

Move::Move(const Move &source) : Move{*source.data} {
    cout << "Copy Constructor for " << *data << endl;
}

Move::Move(Move &&source) noexcept : data{source.data} { // point to the same storage then delete the original pointer of the original object
    source.data = nullptr;
    cout << "Move Constructor - moving resource " << *data << endl;
}

int main() {
    vector <Move> vec;

    vec.push_back(Move{10});
    vec.push_back(Move{20});
    vec.push_back(Move{30});
    vec.push_back(Move{40});
    vec.push_back(Move{50});
    vec.push_back(Move{60});
    vec.push_back(Move{70});
    vec.push_back(Move{80});
}