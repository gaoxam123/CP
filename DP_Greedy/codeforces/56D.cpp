// https://codeforces.com/contest/56/problem/D
#include <bits/stdc++.h>
using namespace std;

string a, b;
int dp[1005][1005];

void solve(int i, int j) {
    if(i < 0 && j < 0) return;
    if(a[i] == b[j]) solve(i - 1, j - 1);
    else {
        if(dp[i][j] == dp[i - 1][j] + 1) {
            cout << "DELETE " << i << endl;
            solve(i - 1, j);
        }
        else if(dp[i][j] == dp[i - 1][j - 1] + 1) {
            cout << "REPLACE " << i << " " << b[j] << endl;
            solve(i - 1, j - 1);
        }
        else if(dp[i][j] == dp[i][j - 1] + 1) {
            cout << "INSERT " << i + 1 << " " << b[j] << endl;
            solve(i, j - 1);
        }
    }
}

int main() {
    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    a = " " + a;
    b = " " + b;
    for(int i = 0; i <= m; i ++) {
        dp[0][i] = i;
    }
    for(int i = 0; i <= n; i ++) {
        dp[i][0] = i;
    }
    for(int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if(a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                // replace: i - 1, j - 1
                // add: i, j - 1
                // delete: i - 1, j
                dp[i][j] = min(min(dp[i - 1][j - 1], dp[i][j - 1]), dp[i - 1][j]) + 1; 
            }
        }
    }
    cout << dp[n][m] << endl;
    solve(n, m);
    // int i = n, j = m;
    // while(i > 0 || j > 0) {
    //     if(a[i] == b[j]) {
    //         i --;
    //         j --;
    //         continue;
    //     }
    //     if(dp[i][j] == dp[i - 1][j] + 1) {
    //         cout << "DELETE " << i << endl;
    //         i --;
    //     }
    //     else if(dp[i][j] == dp[i - 1][j - 1] + 1) {
    //         cout << "REPLACE " << i << " " << b[j] << endl;
    //         i --;
    //         j --;
    //     }
    //     else if(dp[i][j] == dp[i][j - 1] + 1) {
    //         cout << "INSERT " << i + 1 << " " << b[j] << endl;
    //         j --;
    //     }
    // }
}