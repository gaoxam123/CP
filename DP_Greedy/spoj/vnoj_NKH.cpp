// https://oj.vnoi.info/problem/nkh
#include <bits/stdc++.h>
using namespace std;

string a, b, c;
string ans;
int n;

void solve(int i, int j, int k) {
    if(i == n) return;
    if(c[i] == a[j]) {
        ans[i] = '1';
        solve(i + 1, j + 1, k);
    }
    if(c[i] == b[k]) {
        ans[i] = '2';
        solve(i + 1, j, k + 1);
    }
}

int main() {
    cin >> a >> b >> c;
    int i = 0, j = 0, k = 0;
    n = a.size();
    solve(0, 0, 0);
    cout << ans;
}