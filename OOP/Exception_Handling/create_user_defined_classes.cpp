#include<bits/stdc++.h>
using namespace std;

class DivideBy0Exception {

};

class NegativeValueException {

};

double cal_mvg(int miles, int gallons) {
    if(gallons == 0) 
        throw DivideBy0Exception();
    if(miles < 0 || gallons < 0)
        throw NegativeValueException();
    return static_cast<double>(miles) / gallons;
}

int main() {
    int miles, gallons;
    double mpg;

    cin >> miles >> gallons;

    try {
        mpg = cal_mvg(miles, gallons);
        cout << mpg << endl;
    }
    catch(const DivideBy0Exception &er) {
        cerr << "cant divide 0" << endl;
    }
    catch(const NegativeValueException &er) {
        cerr << "no negative values" << endl;
    } 
}