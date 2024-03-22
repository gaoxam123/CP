#include<bits/stdc++.h>
using namespace std;

double n;

int main() {
    cin >> n;

    double l = 0, r = n, mid, sqr, ans;
    for(int i = 1; i <= n; i ++) {
        if(i * i == n) {
            cout << i;
            return 0;
        }
    }
    while(l <= r) {
        mid = (l + r) / 2;
        sqr = mid * mid;
        if((sqr <= n && (n - sqr) < 0.000001) || (sqr == n)) {
            cout << mid;
            return 0;
        }
        if(mid * mid > n) r = mid;
        else {
            l = mid;
            ans = mid;
        }
    }
    cout << ans;
}