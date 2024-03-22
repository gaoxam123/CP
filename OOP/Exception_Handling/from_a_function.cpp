#include <bits/stdc++.h>
using namespace std;

double cal_avg(int sum, int total) {
    if(total == 0) 
        throw 0;
    return static_cast<double>(sum) / total;
}

int main() {
    double avg{};
    int sum, total;
    cin >> sum >> total;

    try {
        avg = cal_avg(sum, total);
        cout << avg << endl;
    }
    catch (int &er) {
        cerr << "no chance" << endl;
    }
}