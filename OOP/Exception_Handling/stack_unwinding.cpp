#include<bits/stdc++.h>
using namespace std;

void func_a() {
    cout << "start a" << endl;
    func_b();
    cout << "end a" << endl;
}

void func_b() {
    cout << "start b" << endl;
    try {
        func_c();
    }
    catch(int &er) {
        cout << "error caught in b" << endl;
    }
    cout << "end b" << endl;
} 

void func_c() {
    cout << "start c" << endl;
    throw 100;
    cout << "end c" << endl;
}

int main() {
    cout << "start main" << endl;
    try {
        func_a();
    }
    catch(int &er) {
        cout << "error caught" << endl;
    }
    cout << "finish main" << endl;
}