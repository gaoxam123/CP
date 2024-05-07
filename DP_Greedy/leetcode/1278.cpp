// https://leetcode.com/problems/palindrome-partitioning-iii/description/
#include <bits/stdc++.h>
using namespace std;

string s;
int K, dp[105][105], f[105][105];

int main() {
    cin >> s;
    cin >> K;
    int n = s.size();
    s = " " + s;
    memset(dp, 0x3f, sizeof(dp));
    memset(f, 0x3f, sizeof(f));
    for(int i = 0; i <= n; i ++) {
        dp[i][0] = 0;
        if(i <= K) dp[i][i] = 0;
        if(i >= 1) f[i][i] = 0;
    }
    for(int i = n - 1; i >= 1; i --) {
        for(int j = i + 1; j <= n; j ++) {
            if(i + 1 == j) {
                if(s[i] == s[j]) f[i][j] = 0;
                else f[i][j] = 1;
            }
            else {
                if(s[i] == s[j]) f[i][j] = f[i + 1][j - 1];
                else {
                    f[i][j] = f[i + 1][j - 1] + 1;
                }
            }
        }
    }
    for(int i = 2; i <= n; i ++) {
        dp[i][1] = f[1][i];
    }
    for(int k = 2; k <= K; k ++) {
        for(int i = k + 1; i <= n; i ++) {
            for(int j = i - 1; j >= k - 1; j --) {
                dp[i][k] = min(dp[i][k], dp[j][k - 1] + f[j + 1][i]);
            }
        }
    }
    cout << dp[n][K];
}