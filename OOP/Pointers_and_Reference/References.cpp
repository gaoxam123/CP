#include <bits/stdc++.h>
using namespace std;

int main() {
    int num{100};
    int &ref{num};
    
    cout << ref << endl; // 100

    vector <string> names{"a", "b", "c"};

    for(auto &str: names) {
        str = "fuck"; // this changes every elements in the vector
    }
    for(auto const &str: names) { // const makes this read only references
        cout << str << " "; 
    }
}