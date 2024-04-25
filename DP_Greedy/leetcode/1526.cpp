// https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/description/
#include <bits/stdc++.h>
using namespace std;

int n, a[100005], dp[100005];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    dp[1] = a[1];
    for(int i = 2; i <= n; i ++) {
        if(a[i] <= a[i - 1]) dp[i] = dp[i - 1];
        else dp[i] = dp[i - 1] + (a[i] - a[i - 1]);
    }
    cout << dp[n];
}