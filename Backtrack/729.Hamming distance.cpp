// https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=670
#include <bits/stdc++.h>
using namespace std;

int t, n, h;
vector <int> a;

// main idea: find all permutations and check if one is valid

void backtrack(int pos) {
    if(pos == n) {
        int check = 0;
        for(int i = 0; i < a.size(); i ++) {
            if(a[i] == 1) check ++;
        }
        if(check == h) {
            for(int i = 0; i < a.size(); i ++) {
                cout << a[i];
            }
            cout << endl;
        }
        return;
    }
    for(int i = 0; i < 2; i ++) {
        a[pos] = i;
        backtrack(pos + 1);
    }
}

int main() {
    cin >> t;
    while(t --) {
        cin >> n >> h;
        backtrack(0);
    }
}