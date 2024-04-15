// https://oj.vnoi.info/problem/bedao_r08_funfair
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, x, y, a[1000005], ans = -1e18, L1[1000005], R1[1000005], sum[1000005], l, r, L2[1000005], R2[1000005];
stack <int> st;

signed main() {
    cin >> n >> x >> y;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        while(!st.empty() && a[st.top()] >= a[i]) st.pop();
        if(!st.empty()) L1[i] = st.top() + 1;
        else L1[i] = 1;
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i = n; i >= 1; i --) {
        while(!st.empty() && a[st.top()] >= a[i]) st.pop();
        if(!st.empty()) R1[i] = st.top() - 1;
        else R1[i] = n;
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i = 1; i <= n; i ++) {
        while(!st.empty() && a[st.top()] > a[i]) st.pop();
        if(!st.empty()) L2[i] = st.top() + 1;
        else L2[i] = n;
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i = n; i >= 1; i --) {
        while(!st.empty() && a[st.top()] > a[i]) st.pop();
        if(!st.empty()) R2[i] = st.top() - 1;
        else R2[i] = n;
        st.push(i);
    }
    for(int i = 1; i <= n; i ++) {
        if(a[i] >= x && a[i] <= y) {
            if(ans < sum[R1[i]] - sum[L1[i] - 1]) {
                ans = sum[R1[i]] - sum[L1[i] - 1];
                l = L1[i];
                r = R1[i];
            }
            if(ans < sum[R2[i]] - sum[L2[i] - 1]) {
                ans = sum[R2[i]] - sum[L2[i] - 1];
                l = L2[i];
                r = R2[i];
            }
            if(ans < a[i]) {
                ans = a[i];
                l = i;
                r = i;
            }
        }
    }
    cout << ans << endl << l << " " << r;
}