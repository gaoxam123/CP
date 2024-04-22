// https://oj.vnoi.info/problem/vosseven
#include <bits/stdc++.h>
using namespace std;
long long dp[1000005], cnt, n;
string s;
int main() {
    getline(cin, s);
    for(int i = 0; i < s.length(); i ++) {
        if(s[i] == '7') {
            cnt ++;
            dp[cnt] ++;
            n=max(n, cnt);
        }
        else cnt = 0;
    }
    if(n == 0) return 0;
    for(int i = n - 1; i >= 1; i --) {
        dp[i] += dp[i + 1];
    }
    for(int i = 1; i <= n; i ++) {
        cout << i << " " << dp[i] << endl;
    }
}
