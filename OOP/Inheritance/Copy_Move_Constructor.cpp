#include <bits/stdc++.h>
using namespace std;

class Base {
private:
    int value;
public:
    Base() : value{0} {}
    Base(int x) : value{x} {}
    ~Base() {}
    Base(const Base &source) : value{source.value} {}
    Base(Base &&source) : value{source.value} {}
    Base &operator=(const Base &rhs) {
        if(this != &rhs) {
            this->value = rhs.value;
        }
        return *this;
    }
};

class Derived: public Base {
private:
    int doubled_value;
public:
    Derived() : Base{}, doubled_value{0} {}
    Derived(int x) : Base{x}, doubled_value{2 * x} {}
    ~Derived() {}
    Derived(const Derived &source) : Base{source}, doubled_value{source.doubled_value} {}
    Derived(Derived &&source) : Base{source}, doubled_value{source.doubled_value} {}
    Derived &operator=(const Derived &rhs) {
        if(this != &rhs) {
            Base::operator=(rhs); // assigning the base part
            this->doubled_value = rhs.doubled_value;
        }
        return *this;
    }
};

int main() {
    Base b{100};
    Derived d;
    Derived a{100};
}