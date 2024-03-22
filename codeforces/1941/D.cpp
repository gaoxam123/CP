// https://codeforces.com/problemset/problem/1941/D
#include<bits/stdc++.h>
using namespace std;

int t, n, m, x;

int main() {
    cin >> t;
    while(t --) {
        cin >> n >> m >> x;
        set <int> s, s1;
        s.clear();
        s1.clear();
        s.insert(x);
        for(int i = 1; i <= m; i ++) {
            char c;
            int r;
            cin >> r >> c;
            if(c != '1') {
                for(int i: s) {
                    s1.insert((i + r - 1) % n + 1);
                }
            }
            if(c != '0') {
                for(int i: s) {
                    s1.insert((i + n - r - 1) % n + 1);
                }
            }
            s = s1;
            s1.clear();
        }
        cout << s.size() << endl;
        for(int i: s) {
            cout << i << " ";
        }
        cout << endl;
    }
}