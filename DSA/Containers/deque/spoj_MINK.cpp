// https://oj.vnoi.info/problem/mink
#include <bits/stdc++.h>
using namespace std;

int t, n, k, a[17005], test[17005];

int main() {
    cin >> t;
    while(t --) {
        int ans = 1e9;
        cin >> n >> k;
        for(int i = 1; i <= n; i ++) {
            cin >> a[i];
        }
        memset(test, 0, sizeof(test));
        deque <int> dq;
        for(int i = 1; i <= n; i ++) {
            while(!dq.empty() && a[dq.back()] >= a[i]) dq.pop_back();
            if(!dq.empty()) test[i] = a[dq.front()];
            else test[i] = a[i];
            dq.push_back(i);
            while(!dq.empty() && dq.front() < i - k + 2) dq.pop_front();
        }
        for(int i = k; i <= n; i ++) {
            ans = min(ans, test[i]);
            cout << test[i] << " ";
        }
        cout << endl;
        // cout << endl << ans << endl;
    }
}