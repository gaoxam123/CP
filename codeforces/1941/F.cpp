// https://codeforces.com/contest/1941/problem/F
#include <bits/stdc++.h>
using namespace std;

int t, n, m, k;

int main() {
    cin >> t;
    while(t --) {
        cin >> n >> m >> k;
        vector<int> a(n + 1), d(m), f(k);
        int max_dist = 0;
        int second_max_dist = 0;
        int index = 00;
        for(int i = 1; i <= n; i ++) {
            cin >> a[i];
            if(i > 1 && a[i] - a[i - 1] >= max_dist) {
                index = i;
                second_max_dist = max_dist;
                max_dist = a[i] - a[i - 1];
            }
            else if(i > 1 && a[i] - a[i - 1] > second_max_dist) {
                second_max_dist = a[i] - a[i - 1];
            }
        }
        for(int i = 0; i < m; i ++) {
            cin >> d[i];
        }
        for(int i = 0; i < k; i ++) {
            cin >> f[i];
        }
        sort(d.begin(), d.end());
        sort(f.begin(), f.end());
        
        if(d[m - 1] + f[k - 1] <= a[index - 1]) {
            cout << max_dist << endl;
            continue;
        }
        int ans = max_dist;
        for(int i = 0; i < m; i ++) {
            // find f[r] around the anchor, which is the midpoint of a[index - 1] and a[index]
            // that means, we find f[r] smallest >= max_function_value and f[r] greatest < max_function_value
            int max_function_value = a[index] - d[i] - max_dist / 2;
            // find the smallest value >= max_function_value
            int r = lower_bound(f.begin(), f.end(), max_function_value) - f.begin();
            if(r != k) {
                int new_problem = f[r] + d[i];
                ans = min(ans, max({second_max_dist, new_problem - a[index - 1], a[index] - new_problem}));
            }
            // find the greatest value < max_function_value
            if(r >= 1) r --;
            int new_problem = f[r] + d[i];
            if(new_problem <= a[index - 1]) continue;
            ans = min(ans, max({second_max_dist, new_problem - a[index - 1], a[index] - new_problem}));
        }
        cout << ans << endl;
    }
}