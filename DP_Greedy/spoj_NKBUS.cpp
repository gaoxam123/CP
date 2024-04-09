// https://oj.vnoi.info/problem/nkbus
#include <bits/stdc++.h>
using namespace std;

int n, m, k, tmp, ans, a[200005];
vector <int> test;

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        int t;
        cin >> t;
        cin >> k;
        for(int j = 1; j <= k; j ++) {
            int x;
            cin >> x;
            x = max(0, x - tmp);
            test.push_back(x);
        }
        tmp += t;
        ans += t;
    }
    sort(test.begin(), test.end());
    int sz = test.size();
    cout << ans + test[m - 1];
}