#include<bits/stdc++.h>
using namespace std;

// Abtract class contains at least 1 pure virtual function
// virtual void function() =0; -> pure virtual function

class Shape { //Abstract
private:
    // attributes common to all shapes
public:
    virtual void draw() = 0; // pure virtual function
    virtual void rotate() = 0;
    virtual ~Shape() {}
};

class Open_Shape: public Shape{ // Abstract
public:
    virtual ~Open_Shape() {}
};

class Closed_Shape: public Shape{ // Abstract
public:
    virtual ~Closed_Shape() {}
};

class Line: public Open_Shape{ // Concrete
public:
    virtual void draw() override {cout << "Line" << endl;}
    virtual void rotate() override {cout << "Rotate Line" << endl;}
    virtual ~Line() {}
};

class Square: public Closed_Shape{ // Concrete
public:
    virtual void draw() override {cout << "Square" << endl;}
    virtual void rotate() override {cout << "Rotate Square" << endl;}
    virtual ~Square() {}
};

class Circle: public Closed_Shape{ // Concrete
private:
    // attributes to all circles
public:
    virtual void draw() override {cout << "Circle" << endl;}
    virtual void rotate() override{cout << "Rotate Circle" << endl;}
    virtual ~Circle() {}
};

int main() {
    // Shape shape -> error
    // Shape *ptr = new Shape() -> error
    Shape *ptr = new Circle();
    ptr->draw();
    ptr->rotate();
}