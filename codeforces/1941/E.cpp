// https://codeforces.com/problemset/problem/1941/E
#include <bits/stdc++.h>
using namespace std;

int t, k, n, m, d;
long long sum[105], dp[200005];

int main() {
    cin >> t;
    while(t --) {
        cin >> n >> m >> k >> d;
        for(int i = 1; i <= n; i ++) {
            deque<int> dq;
            for(int j = 1; j <= m; j ++) {
                int x;
                cin >> x;
                x ++;
                // discard the positions which are too far away(more than d + 1)
                while(!dq.empty() && dq.front() < j - d - 1) dq.pop_front();
                if(j == 1) dp[j] = x;
                else if(j <= d + 2) dp[j] = dp[1] + x;
                else dp[j] = dp[dq.front()] + x;
                // not this far but cost even more -> discard
                while(!dq.empty() && dp[dq.back()] >= dp[j]) dq.pop_back();
                dq.push_back(j);
            }
            sum[i] = sum[i - 1] + dp[m];
        }
        long long ans = 1e18 + 7;
        for(int i = 1; i <= n - k + 1; i ++) {
            ans = min(ans, sum[i + k - 1] - sum[i - 1]);
        }
        cout << ans << endl;
    }
}