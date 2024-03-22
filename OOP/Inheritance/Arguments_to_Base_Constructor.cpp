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
private:
    int doubled_value;
public:
    Derived() : Base{}, doubled_value{0} {}
    Derived(int x) : Base{x}, doubled_value{2 * x} {}
    ~Derived() {}
};

int main() {
    Base b{100};
    Derived d;
    Derived a{100};
}