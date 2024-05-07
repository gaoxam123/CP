// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/description/
#include <bits/stdc++.h>
using namespace std;

int n, K, ans;
pair <pair <int, int>, int> a[1000005];

bool cmp(pair <pair <int, int>, int> x, pair <pair <int, int>, int> y) {
    return x.first.second < y.first.second;
}

int main() {
    cin >> n >> K;
    vector <vector <int> > dp(n + 1, vector <int> (K + 1, 0));
    for(int i = 1; i <= n; i ++) {
        cin >> a[i].first.first >> a[i].first.second >> a[i].second;
    }
    sort(a + 1, a + n + 1, cmp);
    dp[1][1] = a[1].second;
    for(int i = 2; i <= n; i ++) {
        int l = 1, r = i - 1, mid, index = 0;
        while(l <= r) {
            mid = (l + r) / 2;
            if(a[mid].first.second < a[i].first.first) {
                index = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        for(int k = 1; k <= min(K, i); k ++) {
            dp[i][k] = dp[i - 1][k];
            dp[i][k] = max(dp[i][k], dp[index][k - 1] + a[i].second);
        }
    }
    for(int i = 1; i <= K; i ++) {
        ans = max(ans, dp[n][i]);
    }
    cout << ans;
}