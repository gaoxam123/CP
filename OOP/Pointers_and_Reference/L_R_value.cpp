#include <bits/stdc++.h>
using namespace std;

int main() {
    // L-value
    int x{100};
    x = 1000;
    string name;
    name = "Frank";
    // "Frank" and 1000 are not L-value -> R-value
    int y = x + 20; // (x + 20) is R-value
    int max_num = max(20, 30); // max(20, 30) is R-value
    // only use reference for l-value, since only l-values are addressable
}