// https://oj.vnoi.info/problem/atcoder_dp_k
#include <bits/stdc++.h>
using namespace std;

int n, k, a[105], dp[100005];

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        dp[a[i]] = 1;
    }
    for(int i = 1; i <= k; i ++) {
        if(dp[i] == 0) {
            int check = 0;
            for(int j = 1; j <= n; j ++) {
                if(a[j] > i) break;
                if(!dp[i - a[j]]) check = 1;
            }
            if(check == 1) dp[i] = 1;
        }
    }
    if(dp[k] == 1) cout << "First";
    else cout << "Second";
}