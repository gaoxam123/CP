// https://oj.vnoi.info/problem/mfish
#include <bits/stdc++.h>
using namespace std;

int n, sum[100005], anchor[100005], b[100005], d[100005], dp[100005];
int m;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        sum[i] = sum[i - 1] + x;
    }
    cin >> m;
    for(int i = 1; i <= m; i ++) {
        cin >> b[i] >> d[i];
    }
    // have to sort first
    b[m + 1] = n + 1;
    // determine which cell could be a potential anchor position
    for(int i = 1; i <= m; i ++) {
        for(int j = b[i]; j <= min(b[i + 1] - 1, b[i] + d[i] - 1); j ++) {
            if(j - d[i] + 1 > b[i - 1]) anchor[j] = i;
        }
    }
    // anchor this ship or not
    for(int i = 1; i <= n; i ++) {
        if(anchor[i] == 0) dp[i] = dp[i - 1];
        else dp[i] = max(dp[i - 1], dp[i - d[anchor[i]]] + sum[i] - sum[i - d[anchor[i]]]);
    }
    cout << dp[n];
}