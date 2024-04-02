// https://www.spoj.com/PTIT/problems/SSAM219G/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int t, n, a[100005];

signed main() {
    cin >> t;
    while(t --) {
        cin >> n;
        for(int i = 1; i <= n; i ++) {
            cin >> a[i];
        }
        int l[n + 1], r[n + 1];
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));
        stack <int> st;
        for(int i = 1; i <= n; i ++) {
            while(!st.empty() && a[st.top()] >= a[i]) st.pop();
            if(!st.empty()) l[i] = st.top() + 1;
            else l[i] = 1;
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = n; i >= 1; i --) {
            while(!st.empty() && a[st.top()] >= a[i]) st.pop();
            if(!st.empty()) r[i] = st.top() - 1;
            else r[i] = n;
            st.push(i);
        }
        int ans = -1;
        for(int i = 1; i <= n; i ++) {
            int area = (r[i] - l[i] + 1) * a[i];
            ans = max(ans, area);
        }
        cout << ans << endl;
    }
}