// https://codeforces.com/problemset/problem/313/D
#include <bits/stdc++.h>
using namespace std;

int n, m, K, dp[305][305], ans = 1e9;

struct gg {
    int l, r, c;
    gg(int e, int f, int g) {
        l = e, r = f, c = g;
    }
    bool operator < (const gg &other) const {
        return r < other.r;
    }
};

vector <gg> a;

int main() {
    cin >> n >> m >> K;
    for(int i = 1; i <= m; i ++) {
        int l, r, c;
        cin >> l >> r >> c;
        a.push_back({l, r, c});
    }
    sort(a.begin(), a.end());
    // for(int i = 0; i < m; i ++) {
    // 	cout << a[i].l << " " << a[i].r << " " << a[i].c << endl;
    // }
    memset(dp, 0x3f, sizeof(dp));
    for(int i = 1; i <= n; i ++) {
        dp[0][i] = 0;
    }
    for(int k = 1; k <= n; k ++) {
        for(int i = 1; i <= n; i ++) {
            for(int j = 0; j < m; j ++) {
                if(i - a[j].l >= 0 && i - a[j].l <= k - 1 && i <= a[j].r) {
                    dp[k][i] = min(dp[k][i], dp[k - 1][a[j].l - 1] + a[j].c);
                    // if(k == 1) cout << j << endl;
                }
            }
            dp[k][i] = min(dp[k][i], dp[k - 1][i]);
        }
    }
    for(int k = K; k <= n; k ++) {
        ans = min(ans, dp[k][n]);
    }
    cout << ans;
}

// 269B, 273D, 283C, 464C, 429B, 383D, 366C, 346B, 331C2