// https://www.hackerrank.com/contests/ioi-2014-practice-contest-2/challenges/guardians-lunatics-ioi14
#include <bits/stdc++.h>
using namespace std;
#define int long long

int L, G, a[8005];
int dp[805][8005], f[805][8005];
int sum[8005];

// NOT OPTIMZIED VERSION

// signed main() {
//     cin >> L >> G;
//     for(int i = 1; i <= L; i ++) {
//         cin >> a[i];
//         sum[i] = sum[i - 1] + a[i];
//     }
//     for(int i = 1; i <= G; i ++) {
//         for(int j = 0; j <= L; j ++) {
//             if(i == 1) {
//                 dp[i][j] = sum[j] * j;
//             }
//             else {
//                 dp[i][j] = 1e18;
//                 for(int k = 0; k <= j; k ++) {
//                     dp[i][j] = min(dp[i - 1][k] + (sum[j] - sum[k]) * (j - k), dp[i][j]);
//                 }
//             }
//         }
//     }
//     cout << dp[G][L];
//}

int cost(int i, int j) {
    return (sum[j] - sum[i - 1]) * (j - i + 1);
}

void solve(int g, int l, int r, int optL, int optR) {
    if(l > r) return;
    int mid = (l + r) / 2;
    dp[g][mid] = 1e18;
    int k;
    for(int i = optL; i <= optR; i ++) {
        int new_cost = dp[g - 1][i] + cost(i + 1, mid);
        if(dp[g][mid] > new_cost) {
            dp[g][mid] = new_cost;
            k = i;
        }
    }
    solve(g, l, mid - 1, optL, k);
    solve(g, mid + 1, r, k, optR);
}

signed main() {
    cin >> L >> G;
    for(int i = 1; i <= L; i ++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    for(int i = 1; i <= L; i ++) {
        dp[1][i] = cost(1, i);
    }
    for(int g = 2; g <= G; g ++) {
        solve(g, 1, L, 1, L);
    }
    cout << dp[G][L];
}