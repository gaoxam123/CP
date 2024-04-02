// https://oj.vnoi.info/problem/backtrack_e
#include <bits/stdc++.h>
using namespace std;

int n, k;
long long ans = -1e9;
long long a[15];
long long b[15];
vector <long long> test;

void backtrack(int pos, int remain_sum) {
    if(pos == n) {
        long long total_water = 0;
        for(int i = 1; i < n; i ++) {
            b[i] = a[i] + test[i - 1];
        }
        b[n] = a[n] + remain_sum;
        int l[n + 5], r[n + 5];
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));
        for(int i = 1; i <= n; i ++) {
            if(i == 1) l[i] = 0;
            l[i] = max((long long)l[i - 1], (long long)b[i - 1]);
        }
        for(int i = n; i >= 1; i --) {
            if(i == n) r[i] = 0;
            r[i] = max((long long)r[i + 1], b[i + 1]);
        }
        for(int i = 1; i <= n; i ++) {
            total_water += max((long long)0, min(l[i], r[i]) - b[i]);
        }
        ans = max(ans, total_water);
        // cout << test.size() << endl;
        return;
    }
    for(int i = 0; i <= remain_sum; i ++) {
        test.push_back(i);
        backtrack(pos + 1, remain_sum - i);
        test.pop_back();
    }
}

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    backtrack(1, k);
    cout << ans;
}