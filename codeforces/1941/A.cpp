// https://codeforces.com/problemset/problem/1941/A
#include <bits/stdc++.h>
using namespace std;

int t, n, m, k;

int main() {
    cin >> t;

    while(t --) {
        cin >> n >> m >> k;
        int a[n], b[m], cnt = 0;
        
        for(int i = 0; i < n; i ++) {
            cin >> a[i];
        }

        for(int i = 0; i < m; i ++) {
            cin >> b[i];
        }

        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
                if(a[i] + b[j] <= k) cnt ++;
            }
        }
        cout << cnt << endl;
    }
}