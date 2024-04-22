// https://codeforces.com/problemset/problem/1881/E
#include <bits/stdc++.h>
using namespace std;

int t, n, a[200005], dp[200005];

int main() {
    cin >> t;
    while(t --) {
        map <int, int> index_back, index_forth;
        cin >> n;
        for(int i = 1; i <= n; i ++) {
            cin >> a[i];
            if(!index_back[i + a[i]]) index_back[i + a[i]] = i;
            if(i + a[i] <= n) index_forth[i] = i + a[i];
        }
        for(int i = 1; i <= n; i ++) {
            if(index_back[i] != 0) {
                dp[i] = max(dp[i - 1], dp[index_back[i] - 1] + a[index_back[i]] + 1);
                // if(dp[i - 1] >= dp[index[i] - 1] + a[index[i]] + 1) index[i] = i;
            }
            else dp[i] = dp[i - 1];
            if(dp[i - 1] >= dp[index_back[index_forth[i]] - 1] + a[index_back[index_forth[i]]] - a[i]) index_back[index_forth[i]] = i;
        }
        cout << n - dp[n] << endl;
        memset(dp, 0, sizeof(dp));
    }
}