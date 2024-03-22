#include <bits/stdc++.h>
using namespace std;

class Base {
private:
    int value;
public:
    Base() : value{0} {}
    Base(int x) : value{x} {}
    ~Base() {}
};

class Derived: public Base {
    using Base::Base; // use 1-arg Base Constructor, only take care of the base part
private:
    int doubled_value;
public:
    Derived() : doubled_value{0} {}
    Derived(int x) : doubled_value{2 * x} {}
    ~Derived() {}
};

int main() {
    Base b{100};
    Derived a{100}; // call 1-arg Derived Constructor, still use 0-arg Base Constructor
}