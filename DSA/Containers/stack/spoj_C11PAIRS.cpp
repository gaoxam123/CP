// https://oj.vnoi.info/problem/c11pairs
#include <bits/stdc++.h>
using namespace std;

int n, x;
long long ans;
stack <int> st;
map <int, int> cnt;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> x;
        while(!st.empty() && st.top() < x) {
            cnt[st.top()] --;
            st.pop();
            ans ++;
        }
        if(!st.empty()) {
            ans += x == st.top() ? cnt[x] + (st.size() > cnt[x]) : 1;
        }
        st.push(x);
        cnt[x] ++;
    }
    cout << ans;
}