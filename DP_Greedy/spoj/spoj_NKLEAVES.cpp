// https://oj.vnoi.info/problem/nkleaves
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, k, a[100005], dp[15][100005], sum[100005], product_sum[100005];

int cost(int i, int j) {
    if(i > j) return 0;
    return product_sum[j] - product_sum[i] - i * (sum[j] - sum[i]);
}

void solve(int i, int l, int r, int optL, int optR) {
    if(l > r) return;
    int mid = (l + r) / 2;
    dp[i][mid] = 1e18;
    int pivot = 0;
    for(int j = optL; j <= min(mid, optR); j ++) {
        int new_cost = dp[i - 1][j - 1] + cost(j, mid);
        if(dp[i][mid] > new_cost) {
            dp[i][mid] = new_cost;
            pivot = j;
        }
    }
    solve(i, l, mid - 1, optL, pivot);
    solve(i, mid + 1, r, pivot, optR);
}

signed main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        product_sum[i] = product_sum[i - 1] + i * a[i];
    }
    for(int i = 1; i <= n; i ++) {
        dp[1][i] = cost(1, i);
    }
    for(int i = 2; i <= k; i ++) {
        // for(int j = 1; j <= n; j ++) {
        //     dp[i][j] = 1e9;
        //     for(int t = i; t <= j; t ++) {
        //         int new_cost = dp[i - 1][t - 1] + cost(t, j);
        //         if(dp[i][j] > new_cost) dp[i][j] = new_cost;
        //     }
        // }
        solve(i, 1, n, 1, n);
    }
    cout << dp[k][n];
}