#include<bits/stdc++.h>
using namespace std;

class Test {
private:
    int data;
public:
    Test() : data{0} {}
    Test(int data) : data{data} {}
    int get_data() const {return data;}
    ~Test() {}
};

void deleter(Test *ptr) { // delete ptr ourselves -> construct ourselves by using 'new'
    delete ptr;
}

int main() {
    // function method
    shared_ptr<Test> ptr1 {new Test{100}, deleter}; // cant use make shared
    
    // lambda expression
    shared_ptr<Test> ptr2 (new Test{100},
        [] (Test *ptr) {
            cout << "Using custom lambda deleter" << endl;
            delete ptr;
        }); 
}