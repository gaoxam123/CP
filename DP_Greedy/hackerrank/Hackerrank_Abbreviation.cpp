// https://www.hackerrank.com/challenges/abbr/problem
#include <bits/stdc++.h>
using namespace std;

int q, dp[1005][1005];
string a, b;

int main() {
    cin >> q;
    while(q --) {
        cin >> a;
        cin >> b;
        memset(dp, 0, sizeof(dp));
        int n = a.size(), m = b.size();
        a = " " + a;
        b = " " + b;
        map <char, int> ma, mb;
        for(int i = 1; i <= n; i ++) {
            if('A' <= a[i] && a[i] <= 'Z') {
                ma[a[i]] ++;
            }
        }
        for(int i = 1; i <= m; i ++) {
            mb[b[i]] ++;
        }
        int check = 0;
        for(auto c = 'A'; c <= 'Z'; c ++) {
            if(ma[c] > mb[c]) check = 1;
        }
        if(check == 1) {
            cout << "NO" << endl;
            continue;
        }
        for(int i = 0; i <= n; i ++) dp[i][0] = 1;
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= m; j ++) {
                if(a[i] == b[j]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if(a[i] - 'a' == b[j] - 'A') {
                    dp[i][j] = dp[i - 1][j - 1] | dp[i - 1][j];
                }
                else if('A' <= a[i] && a[i] <= 'Z') {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        if(!dp[n][m]) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}