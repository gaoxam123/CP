// https://leetcode.com/problems/jump-game-v/description/
#include <bits/stdc++.h>
using namespace std;

int n, a[1005], dp[1005], d, ans;
pair <int, int> b[1005];

int main() {
    cin >> n >> d;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        b[i].first = a[i];
        b[i].second = i;
    }
    sort(b + 1, b + n + 1);
    for(int i = 1; i <= n; i ++) {
        int id = b[i].second;
        int mx = 0;
        for(int j = id + 1; j <= min(n, id + d); j ++) {
            if(a[j] >= a[id]) break;
            else mx = max(mx, dp[j]);
        }
        for(int j = id - 1; j >= max(1, id - d); j --) {
            if(a[j] >= a[id]) break;
            else mx = max(mx, dp[j]);
        }
        dp[id] = mx + 1;
    }
    for(int i = 1; i <= n; i ++) {
        ans = max(ans, dp[i]);
    }
    cout << ans;
}