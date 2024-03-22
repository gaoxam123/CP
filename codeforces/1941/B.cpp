// https://codeforces.com/problemset/problem/1941/B
#include<bits/stdc++.h>
using namespace std;

int t, n;

int main() {
    cin >> t;
    while(t --) {
        cin >> n;
        int a[n + 1];
        bool check = true;

        for(int i = 1; i <= n; i ++) {
            cin >> a[i];
        }
        for(int i = 2; i < n; i ++) {
            int x = min(int(a[i] / 2), min(a[i - 1], a[i + 1]));
            a[i - 1] -= x;
            a[i] -= x * 2;
            a[i + 1] -= x;
        }
        
        for(int i = 1; i <= n; i ++) {
            if(a[i] != 0) {
                check = false;
                break;
            }
        }

        if(check) {
            cout << "YES" << endl;
        }
        else { 
            cout << "NO" << endl;
        }
    }
}