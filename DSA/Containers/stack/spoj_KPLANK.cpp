// https://oj.vnoi.info/problem/kplank
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, a[1000005], l[1000005], r[1000005];

signed main() {
        cin >> n;
        for(int i = 1; i <= n; i ++) {
            cin >> a[i];
        }
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
        int ans = 0;
        for(int i = 1; i <= n; i ++) {
            int side = r[i] - l[i] + 1;
            if(side < a[i]) continue;
            ans = max(ans, min(side, a[i]));
        }
        cout << ans;
}