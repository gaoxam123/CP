#include <bits/stdc++.h>
using namespace std;

class Base{
public:
    virtual void say() const {
        cout << "Base class" << endl;
    }
    virtual ~Base() {}
};

class Derived: public Base{
public:
    virtual void say() const override {
        cout << "Derived class" << endl;
    }
    virtual ~Derived() {}
};

int main() {
    Base *p1 = new Base();
    p1->say();

    Derived *p2 = new Derived();
    p2->say();

    Base *p3 = new Derived();
    p3->say();
}