// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/
#include <bits/stdc++.h>
using namespace std;

string s;
int dp[505][505];

int main() {
    cin >> s;
    int n = s.size();
    s = " " + s;
    for(int i = n - 1; i >= 1; i --) {
        for(int j = i + 1; j <= n; j ++) {
            if(s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1];
            else dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
        }
    }
    cout << dp[1][n];
}