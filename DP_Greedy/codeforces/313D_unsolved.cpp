// https://codeforces.com/problemset/problem/313/D
#include <bits/stdc++.h>
using namespace std;
#define int long long

vector <int> id[305];
int n, m, K, dp[305][305], ans = 1e18;
pair <pair <int, int>, int> a[100005];

bool cmp(pair <pair <int, int>, int> x, pair <pair <int, int>, int> y) {
    if(x.first.second < y.first.second) return true;
    else if(x.first.second == y.first.second) return x.first.first < y.first.first;
}

signed main() {
    cin >> n >> m >> K;
    for(int i = 1; i <= m; i ++) {
        cin >> a[i].first.first >> a[i].first.second >> a[i].second;
    }
    sort(a + 1, a + m + 1, cmp);
    for(int i = 0; i <= n; i ++) {
        for(int k = 0; k <= n; k ++) {
            dp[i][k] = 1e18;
        }
    }
    for(int i = 0; i <= n; i ++) {
        dp[i][0] = 0;
        if(i >= 1) {
            for(int j = 1; j <= m; j ++) {
                if(a[j].first.first <= i && a[j].first.second >= i) {
                    id[i].push_back(j);
                }
            }
        }
    }
    for(int i = 1; i <= n; i ++) {
        for(int k = 1; k <= min(i, K); k ++) {
            dp[i][k] = dp[i - 1][k];
            for(int j: id[i]) {
                dp[i][k] = min(dp[i][k], dp[i - (i - a[j].first.first + 1)][max((int)0, k - (i - a[j].first.first + 1))] + a[j].second);
            }
        }
    }
    for(int k = K; k <= n; k ++) {
        ans = min(ans, dp[n][k]);
    }
    if(ans < 1e18) cout << ans;
    else cout << "-1";
}

// 269B, 283C, 429B