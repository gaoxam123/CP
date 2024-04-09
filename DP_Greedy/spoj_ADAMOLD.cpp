// https://www.spoj.com/problems/ADAMOLD/
#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long

int n, k, a[5005], sum[5005][5005], sum_lr[5005][5005], dp[5005][5005];

void solve(int i, int l, int r, int optL, int optR) {
    if(l > r) return;
    int mid = (l + r) >> 1;
    dp[i][mid] = 1e18;
    int pivot = 0;
    for(int j = optL; j <= min(mid, optR); j ++) {
        int new_cost = dp[i - 1][j] + sum_lr[j + 1][mid];
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
    }
    for(int i = 1; i < n; i ++) {
        for(int j = i + 1; j <= n; j ++) {
            sum[i][j] = sum[i][j - 1] + (a[i] ^ a[j]);
        }
    }
    for(int j = 2; j <= n; j ++) {
    	for(int i = j; i >= 1; i --) {
    		sum_lr[i][j] = sum_lr[i + 1][j] + sum[i][j];  
    	}
    }
    for(int i = 1; i <= n; i ++) {
        dp[1][i] = sum_lr[1][i]; 
    }
    for(int i = 2; i <= k + 1; i ++) {
        // for(int j = 1; j <= n; j ++) {
        //     dp[i][j] = 1e18;
        //     for(int t = 0; t <= j; t ++) {
        //         int new_cost = dp[i - 1][t] + sum_lr[t + 1][j];
        //         if(dp[i][j] > new_cost) dp[i][j] = new_cost;
        //     }
        // }
        solve(i, 1, n, 1, n);
    }
    cout << dp[k + 1][n];
}