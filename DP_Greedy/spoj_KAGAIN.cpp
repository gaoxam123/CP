// https://oj.vnoi.info/problem/kagain
#include <bits/stdc++.h>
using namespace std;

int t, n, a[30005];

int main() {
    cin >> t;
    while(t --) {
        cin >> n;
        for(int i = 1; i <= n; i ++) {
            cin >> a[i];
        }
        stack <int> st;
        int l[n + 5], r[n + 5];
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));
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
        int ans = 0, left, right;
        for(int i = 1; i <= n; i ++) {
            if((r[i] - l[i] + 1) * a[i] > ans) {
                ans = (r[i] - l[i] + 1) * a[i];
                left = l[i];
                right = r[i];
            }
        }
        cout << ans << " " << left << " " << right << endl;
    }
}