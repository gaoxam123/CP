// https://codeforces.com/problemset/problem/1741/E
#include <bits/stdc++.h>
using namespace std;

int t, n, a[200005], dp[200005];

int main() {
    cin >> t;
    while(t --) {
        map <int, int> index_back;
        map <int, int> index_forth;
        map <int, int> erase_left;
        cin >> n;
        for(int i = 1; i <= n; i ++) {
            cin >> a[i];
            if(!index_back[i + a[i]]) index_back[i + a[i]] = i;
            if(i + a[i] <= n) index_forth[i] = i + a[i];
            if(i - a[i] >= 1) erase_left[i] = i - a[i];
        }
        for(int i = 1; i <= n; i ++) {
            dp[i] = dp[i - 1];
            if(index_back[i] != 0) {
                dp[i] = max(dp[i], dp[index_back[i] - 1] + a[index_back[i]] + 1);
            }
            if(erase_left[i] != 0) {
                dp[i] = max(dp[i], dp[erase_left[i] - 1] + a[i] + 1);
            }
            if(dp[i - 1] >= dp[index_back[index_forth[i]] - 1] + a[index_back[index_forth[i]]] - a[i]) index_back[index_forth[i]] = i;
        }
        if(dp[n] == n) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}