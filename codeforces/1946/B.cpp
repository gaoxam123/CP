#include <bits/stdc++.h>
using namespace std;
#define int long long

int t, n, k, a[200005], ans, sum;
int mod = 1e9 + 7;

signed main() {
    cin >> t;
    while(t --) {
        sum = 0;
        int total = 0;
        ans = INT_MIN;
        cin >> n >> k;
        for(int i = 1; i <= n; i ++) {
            cin >> a[i];
            // a[i] = ((a[i] % mod) + mod) % mod;
            total += a[i];
            total = ((total % mod) + mod) % mod;
        }
        for(int i = 1; i <= n; i ++) {
            sum = max(a[i], sum + a[i]);
            ans = max(ans, sum);
        }

        // int max_subarray = ans;
        // if(max_subarray < 0) max_subarray = 0;
        // max_subarray = ((max_subarray % mod) + mod) % mod;
        // int remaining_sum = total - ans;
        // remaining_sum = ((remaining_sum % mod) + mod) % mod;
        // int res = 0;

        // for(int i = 1; i <= k; i ++) {
        //     max_subarray = (max_subarray * 2) % mod;
        //     max_subarray = (max_subarray + mod) % mod;
        // }
        // res += max_subarray;
        // res = ((res % mod) + mod) % mod;
        // res += remaining_sum;
        // res = ((res % mod) + mod) % mod;

        int res = 0;
        ans = max(ans, (long long)0);
        res = ans;
        for(int i = 1; i <= k; i ++) {
            ans = (ans * 2) % mod;
            ans = ((ans % mod) + mod) % mod;
        }
        res = ((ans + (total - res)) % mod + mod) % mod;
        cout << res << endl;
    }
}