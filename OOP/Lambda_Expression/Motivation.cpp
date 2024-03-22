#include<bits/stdc++.h>
using namespace std;

struct Square_Functor {
    void operator() (int x) {
        cout << x * x << endl;
    }
};

template <typename T>
struct Displayer {
    void operator() (const T &data) {
        cout << data << endl;
    }
};

class Multiplier {
private:
    int num;
public:
    Multiplier(int num) : num{num} {}
    int operator() (int n) {
        return num * n;
    }
};

int main() {
    Square_Functor square;
    square(4); // square.operator()(4) displays 16

    Displayer<int> d1; // because of template class T
    Displayer<string> d2;
    d1(100); // displays 100
    d2("Frank"); // displays Frank

    vector<int> vec1{1, 2, 3, 4, 5};
    vector<string> vec2{"a", "b", "c"};

    for_each(vec1.begin(), vec1.end(), square);
    cout << endl;

    for_each(vec1.begin(), vec1.end(), Displayer<int>());
    cout << endl;

    for_each(vec1.begin(), vec1.end(), d1);
    cout << endl;

    for_each(vec2.begin(), vec2.end(), Displayer<string>());
    cout << endl;

    for_each(vec2.begin(), vec2.end(), d2);
    cout << endl;

    //

    for_each(vec1.begin(), vec1.end(), [](int x) {cout << x * x << " ";});
    cout << endl;

    for_each(vec1.begin(), vec1.end(), [](int x) {cout << x * 10 << " ";});
    cout << endl;

    for_each(vec1.begin(), vec1.end(), [](int x) {cout << x << " ";});
    cout << endl;

    for_each(vec2.begin(), vec2.end(), [](string s) {cout << s << " ";});
    cout << endl;

    //

    Multiplier mult(100);
    vec1 = {1, 2, 3, 4};
    transform(vec1.begin(), vec1.end(), vec1.begin(), mult);
    for_each(vec1.begin(), vec1.end(), d1);
    cout << endl;

    vec1 = {1, 2, 3, 4};
    transform(vec1.begin(), vec1.end(), vec1.begin(), [](int x) {return x * 100;});
    for_each(vec1.begin(), vec1.begin(), [](int x) {cout << x << " ";});
}