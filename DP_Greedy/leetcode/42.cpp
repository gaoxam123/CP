// https://leetcode.com/problems/trapping-rain-water/description/
#include <bits/stdc++.h>
using namespace std;

int n, a[20005], L[20005], R[20005], ans;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for(int i = 2; i <= n; i ++) {
        L[i] = max(L[i - 1], a[i - 1]);
    }
    for(int i = n - 1; i >= 1; i --) {
        R[i] = max(R[i + 1], a[i + 1]);
    }
    for(int i = 1; i <= n; i ++) {
        ans += max(0, min(L[i], R[i]) - a[i]);
    }
    cout << ans;
} 