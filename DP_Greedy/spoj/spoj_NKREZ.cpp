// https://oj.vnoi.info/problem/nkrez
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, dp[15005];
pair <int, int> t[15005];

bool cmp(pair <int, int> &x, pair <int, int> &y) {
    return x.second < y.second;
}

int binary(int l, int r, int val) {
    int ans = 0;
    while(l <= r) {
        int m = (l + r) / 2;
        if(t[m].second <= val){
            ans = m;
            l = m + 1;
        }
        else r = m - 1;
    }
    return ans;
}

signed main() {
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> t[i].first >> t[i].second;
    }
    sort(t + 1, t + n + 1, cmp);
    dp[1] = t[1].second - t[1].first;
    for(int i = 2; i <= n; i ++) {
        int ind = binary(1, i - 1, t[i].first);
        dp[i] = max(dp[i - 1], dp[ind] + t[i].second - t[i].first);
    }
    cout << dp[n];
}

// #include <bits/stdc++.h>
// using namespace std;

// int n, dp[10005];
// pair <int, int> a[10005];

// bool compare(pair <int, int> a, pair <int, int> b) {
//     return a.second < b.second;
// }

// int main() {
//     cin >> n;
//     for(int i = 1; i <= n; i ++) {
//         cin >> a[i].first >> a[i].second;
//     }
//     sort(a + 1, a + n + 1, compare);
//     dp[1] = a[1].second - a[1].first;
//     for(int i = 2; i <= n; i ++) {
//         for(int j = 1; j < i; j ++) {
//             if(a[j].second <= a[i].first) {
//                 dp[i] = max(dp[i], dp[j] + a[i].second - a[i].first);
//                 dp[i] = max(dp[i], dp[i - 1]);
//             }
//         }
//     }
//     cout << dp[n];
// }