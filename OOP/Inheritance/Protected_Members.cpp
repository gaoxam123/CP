#include <bits/stdc++.h>
using namespace std;

class Base{
public:
    int a{0};
    void display() {cout << a << b << c;}
protected:
    int b{0};
private:
    int c{0};
};

class Derived: public Base {
    // only a and b are accessible, a will be public, b will be protected
public:
};

int main() {
    Base base;
}  