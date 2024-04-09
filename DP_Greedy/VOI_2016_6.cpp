// https://oj.vnoi.info/problem/vodoncay
#include <bits/stdc++.h>
using namespace std;

int n, a[4000005];
int L[4000005]; // the furthest tree falls down if a[i] leans to the left
int R[4000005]; // ... to the right
int dp[4000005]; // min trees to cut down, considering first i elements
int trace[4000005];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        dp[i] = i;
        trace[i] = -i;
    }
    stack <int> S;
    for (int i = 1; i <= n; i ++) {
        L[i] = i;
        while (!S.empty() && S.top() > i - a[i]){
            L[i] = min(L[i], L[S.top()]);
            S.pop();
        }
        S.push(i);
    }
    while(!S.empty()) S.pop();
    for (int i = n; i >= 1; i --) {
        R[i] = i;
        while (!S.empty() && S.top() < i + a[i]){
            R[i] = max(R[i], R[S.top()]);
            S.pop();
        }
        S.push(i);
    }
    stack <int> st;
    for(int i = 1; i <= n; i ++) {
        // if we push the i-th tree to the left, the all trees upto L[i] - 1 have fallen, so we update dp[i] with dp[L[i] - 1]
        if(dp[i] > dp[L[i] - 1] + 1) {
            dp[i] = dp[L[i] - 1] + 1;
            trace[i] = -L[i];
        }
        // i-th tree is pushed to the right by j-th tree with j <= i
        while(!st.empty() && R[st.top()] < i) st.pop();
        if(!st.empty() && dp[i] > dp[st.top() - 1] + 1) {
            dp[i] = dp[st.top() - 1] + 1;
            trace[i] = st.top();
        }
        // after pushing i in the stack, i becomes the top, if dp[top - 1] is not the best, then we don't push i in
        if(st.empty() || (dp[st.top() - 1] > dp[i - 1])) st.push(i);
    }   
    cout << dp[n] << endl;
    for(int i = n; i; i = abs(trace[i]) - 1) {
        cout << (trace[i] < 0 ? -i : trace[i]) << " ";
    }
}