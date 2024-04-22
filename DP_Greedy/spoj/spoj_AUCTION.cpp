// https://oj.vnoi.info/problem/auction
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
int a[1005], ans, id;

signed main() {
    ans = -1e9;
    id = -1;
    cin >> n >> m;
    for(int i = 1; i <= m; i ++) {
        cin >> a[i];
    }
    sort(a + 1, a + m + 1);
    for(int i = 1; i <= m; i ++) {
        int value = a[i] * min((m - i + 1), n);
        if(ans < value) {
            id = i;
            ans = value;
        }
    }
    cout << a[id] << " " << ans;
}