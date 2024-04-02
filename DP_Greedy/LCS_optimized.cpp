#include <bits/stdc++.h>
using namespace std;

int m, n;
int dp[5005][5005];
char a[1000005], b[5005];
int nextPos[1000005][26];

void minimize(int &a, int b) {
    if(a == -1 || a > b) a = b;
}

// main idea: dp[i][j] = k is the smallest k so that LCS(A[1...k], B[1...i]) = j
// dp[i + 1][j] = dp[i][j] -> apparently
// k = nextPos(dp[i][j], B[i + 1]) = dp[i + 1][j + 1]

int main() {
    cin >> a + 1 >> b + 1;
    m = strlen(a + 1);
    n = strlen(b + 1);
    for(int c = 0; c < 26; c ++) {
        for(int i = m - 1; i >= 0; i --) {
            if(a[i + 1] - 'A' == c) nextPos[i][c] = i + 1;
            else nextPos[i][c] = nextPos[i + 1][c];
        }
    }
    int max_length = min(m, n);
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j <= i; j ++) {
            if(dp[i][j] >= 0) {
                minimize(dp[i + 1][j], dp[i][j]);
            }
            int new_value = nextPos[dp[i][j]][b[i + 1] - 'A'];
            if(new_value > 0) {
                minimize(dp[i + 1][j + 1], new_value);
            }
        }
    }
    int ans = 0;
    for(int j = max_length; j > 0; j --) {
        for(int i = j; i <= n; i ++) {
            if(dp[i][j] >= 0) ans = j;
        }
        if(ans != 0) break;
    }
    cout << ans;
}