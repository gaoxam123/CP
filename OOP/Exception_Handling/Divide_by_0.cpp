#include <bits/stdc++.h>
using namespace std;

int main() {
    int miles{};
    int gallons{};
    double miles_per_gallon {};

    cin >> miles >> gallons;

    // miles_per_gallon = miles / gallons; // crash if gallons == 0
    // miles_per_gallon = static_cast<double>(miles) / gallons; // inf if gallons == 0, nan if miles and gallons == 0
    // cout << miles_per_gallon;

    // if(gallons != 0) {
    //     miles_per_gallon = static_cast<double>(miles) / gallons; // inf if gallons == 0, nan if miles and gallons == 0
    //     cout << miles_per_gallon;
    // }
    // else {
    //     cerr << "cant divide by 0" << endl;
    // }
    try {
        if(gallons == 0) 
            throw 0;
        miles_per_gallon = static_cast<double>(miles) / gallons;
        cout << miles_per_gallon << endl;
    }
    catch(int &er) {
        cerr << "cant divide by 0" << endl;
    }
}