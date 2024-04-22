#include <bits/stdc++.h>
using namespace std;
// #define int long long

int n, k;
long long d[5005], w[5005];
long long dp[5005][5005], cost[5005][5005];
int bestcut[5005][5005];

long long compute_cost(int i, int j) {
    return cost[bestcut[i][j]][j] - cost[bestcut[i][j]][i - 1];
}

void solve(int i, int l, int r, int optL, int optR) {
    if(l > r) return;
    int mid = (l + r) / 2;
    dp[i][mid] = 1e18;
    int pos = 0;
    for(int j = optL; j <= min(mid, optR); j ++) {
        long long new_cost = dp[i - 1][j - 1] + compute_cost(j, mid);
        if(dp[i][mid] > new_cost) {
            dp[i][mid] = new_cost;
            pos = j;
        }
    }
    solve(i, l, mid - 1, optL, pos);
    solve(i, mid + 1, r, pos, optR);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) {
        cin >> d[i] >> w[i];
    }
    // cost of putting j first mines at pos i
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= i; j ++) {
            cost[i][j] = cost[i][j - 1] + (d[i] - d[j]) * w[j]; 
        }
        for(int j = i + 1; j <= n; j ++) {
            cost[i][j] = cost[i][j - 1] + (d[j] - d[i]) * w[j];
        }
    }
    for(int i = 1; i <= n; i ++) {
        bestcut[i][i] = i;
    }
    for(int j = 2; j <= n; j ++) {
        for(int i = j - 1; i >= 1; i --) {
            long long c = 1e18;
            for(int k = bestcut[i][j - 1]; k <= bestcut[i + 1][j]; k ++) {
                if(c > cost[k][j] - cost[k][i - 1]) {
                    c = cost[k][j] - cost[k][i - 1];
                    bestcut[i][j] = k;
                }
            }
        }
    }
    for(int i = 1; i <= n; i ++) {
        dp[1][i] = cost[bestcut[1][i]][i];
    }
    for(int g = 2; g <= k; g ++) {
        // for(int i = 1; i <= n; i ++) {
        //     dp[g][i] = 1e9;
        //     for(int j = i; j >= 1; j --) {
        //         dp[g][i] = min(dp[g][i], dp[g - 1][j - 1] + cost[bestcut[j][i]][i] - cost[bestcut[j][i]][j - 1]);
        //     }
        // }
        solve(g, 1, n, 1, n);
    }
    cout << dp[k][n];
}