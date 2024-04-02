// https://oj.vnoi.info/problem/v11water
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, a[100005];
int l[100005], r[100005];

signed main() {
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= n; i ++) {
        if(i == 1) continue;
        l[i] = max(l[i - 1], a[i - 1]);
    }
    for(int i = n; i >= 1; i --) {
        if(i == n) continue;
        r[i] = max(r[i + 1], a[i + 1]);
    }
    int sum = 0;
    for(int i = 1; i <= n; i ++) {
        sum += max((int)0, min(l[i], r[i]) - a[i]);
    }
    cout << sum;
}