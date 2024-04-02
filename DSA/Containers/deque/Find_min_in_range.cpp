#include <bits/stdc++.h>
using namespace std;

int n, k, a[100005];
deque <int> dq;
int ans[100005];

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i ++) {
        while(!dq.empty() && a[dq.back()] >= a[i]) dq.pop_back();
        if(!dq.empty()) ans[i] = dq.front();
        else ans[i] = a[i];
        dq.push_back(i);
        while(dq.front() < i - k + 2) dq.pop_front();
    }
    for(int i = k; i <= n; i ++) {
        cout << ans[i] << " ";
    }
}