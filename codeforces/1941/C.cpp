// https://codeforces.com/problemset/problem/1941/C
#include<bits/stdc++.h>
using namespace std;

int t, n;
string s;

int main() {
    cin >> t;
    while(t --) {
        cin >> n;
        cin >> s;
        int cnt = 0;
        int dem = 0;

        for(int i = 0; i < n - 2; i ++) {
            if(s[i] == 'm' && s[i + 1] == 'a' && s[i + 2] == 'p') {
                cnt ++;
            }
            if(s[i] == 'p' && s[i + 1] == 'i' && s[i + 2] == 'e') {
                cnt ++;
            }
            if(i < n - 4) {
                if(s[i] == 'm' && s[i + 1] == 'a' && s[i + 2] == 'p' && s[i + 3] == 'i' && s[i + 4] == 'e') {
                    dem ++;
                }
            }
        }

        cout << cnt - dem << endl;
    }
}