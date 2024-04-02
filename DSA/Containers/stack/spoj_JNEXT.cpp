// https://www.spoj.com/problems/JNEXT/
#include <bits/stdc++.h>
using namespace std;

int t, n, a[1000005];

int main() {
    cin >> t;
    while(t --) {
        cin >> n;
        stack <int> st;
        int mx = -2;
        int l[n + 1];
        for(int i = 1; i <= n; i ++) {
            cin >> a[i];
            while(!st.empty() && a[st.top()] >= a[i]) st.pop();
            if(!st.empty()) l[i] = st.top();
            else l[i] = -1;
            mx = max(mx, l[i]);
            st.push(i);
        }
        while(!st.empty()) st.pop();
        if(mx == -1) {
            cout << "-1" << endl;
            continue;
        }
        for(int i = n; i >= 1; i --) {
            if(l[i] == mx) {
                int tmp = a[mx];
                a[mx] = a[i];
                a[i] = tmp;
                break;
            }
        }
        int b[n - mx];
        for(int i = 0; i < n - mx; i ++) {
            b[i] = a[i + mx + 1];
        }
        sort(b, b + n - mx);
        for(int i = mx + 1; i <= n; i ++) {
            a[i] = b[i - mx - 1];
        }
        for(int i = 1; i <= n; i ++) {
            cout << a[i];
        }
        cout << endl;
    }
}

// 2
// 5
// 1 5 4 8 3
// 10
// 1 4 7 4 5 8 4 1 2 6