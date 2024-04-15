// https://codeforces.com/problemset/problem/1842/C
#include <bits/stdc++.h>
using namespace std;

int t, n, a[200005], dp[200005];

int main() {
    cin >> t;
    while(t --) {
        cin >> n;
        map <int, int> index;
        index.clear();
        for(int i = 1; i <= n; i ++) {
            cin >> a[i];
            index[a[i]] = 0;
        }
        for(int i = 1; i <= n; i ++) {
            if(index[a[i]] == 0) {
                dp[i] = dp[i - 1];
                index[a[i]] = i;
            }
            else {
                dp[i] = max(dp[i - 1], dp[index[a[i]] - 1] + i - index[a[i]] + 1);
                if(dp[i - 1] >= dp[index[a[i]] - 1] + i - index[a[i]] + 1) {
                    index[a[i]] = i;
                }
            }
        }
        cout << dp[n] << endl;
        memset(dp, 0, sizeof(dp));
    }
}