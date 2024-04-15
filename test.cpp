// https://oj.vnoi.info/problem/ctncln
#include <bits/stdc++.h>
using namespace std;

int n, m, a[40005], dp[40005];

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    dp[1] = 1;
    for(int i = 2; i <= n; i ++) {
        dp[i] = 1e9;
        map <int, int> mp;
        mp[a[i]] = 1;
        int cnt = 1;
        for(int j = i - 1; j >= 1; j --) {
            dp[i] = min(dp[i], dp[j] + cnt * cnt);  
            if(!mp[a[j]]) {
                cnt ++;
                mp[a[j]] = 1;
            }
        }
        cout << dp[i] << endl;
    }
}