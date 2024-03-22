#include <bits/stdc++.h>
using namespace std;

double cal_avg(int sum, int total) {
    if(total == 0) 
        throw 0;
    if(sum < 0 || total < 0) 
        throw string{"Negative value error"};
    return static_cast<double>(sum) / total;
}

int main() {
    int miles{}, gallons{};
    double miles_per_gallon{};

    cin >> miles >> gallons;

    try {
        miles_per_gallon = cal_avg(miles, gallons);
        cout << miles_per_gallon << endl;
    }
    catch(int &er) {
        cerr << "tried to divide by 0" << endl;
    }
    catch(string &er) {
        cerr << er << endl;
    }
    catch(...) { // everything else
        
    }
}