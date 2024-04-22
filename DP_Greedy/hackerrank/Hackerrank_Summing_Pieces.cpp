// https://www.hackerrank.com/challenges/summing-pieces/problem?isFullScreen=true
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, p[1000005], mod = 1e9 + 7, res;

signed main() {
    p[0] = 1;
    for(int i = 1; i <= 1000002; i ++) {
        p[i] = (2 * p[i - 1]) % mod;
    }
    cin >> n;
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        int mul = ((p[i + 1] + p[i] - 1) * p[n - i - 1] - p[i] + mod) % mod;
        res += x * mul % mod;
        res %= mod;
    }
    cout << res;
}