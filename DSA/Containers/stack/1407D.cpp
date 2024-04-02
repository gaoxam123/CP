// https://codeforces.com/contest/1407/problem/D
#include <bits/stdc++.h>
using namespace std;

int n, a[300005];
vector <int> adj[300005];
queue <int> q;
int d[300005], visited[300005];
int l_max[300005], r_max[300005];
int l_min[300005], r_min[300005];

void bfs(int x) {
    visited[x] = 1;
    q.push(x);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v: adj[u]) {
            if(!visited[v]) {
                visited[v] = 1;
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        if(i < n) {
            adj[i].push_back(i + 1);
        }
    }
    stack <int> st;
    for(int i = 1; i <= n; i ++) {
        while(!st.empty() && a[st.top()] <= a[i]) st.pop();
        if(!st.empty()) l_max[i] = st.top();
        else l_max[i] = 0;
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i = n; i >= 1; i --) {
        while(!st.empty() && a[st.top()] <= a[i]) st.pop();
        if(!st.empty()) r_max[i] = st.top();
        else r_max[i] = n + 1;
        st.push(i);
    }
    while(!st.empty()) st.pop();
    
    for(int i = 1; i <= n; i ++) {
        while(!st.empty() && a[st.top()] >= a[i]) st.pop();
        if(!st.empty()) l_min[i] = st.top();
        else l_min[i] = 0;
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i = n; i >= 1; i --) {
        while(!st.empty() && a[st.top()] >= a[i]) st.pop();
        if(!st.empty()) r_min[i] = st.top();
        else r_min[i] = n + 1;
        st.push(i);
    }
    for(int i = 1; i <= n; i ++) {
        if(l_max[i] != 0 && r_max[i] != n + 1) {
            adj[l_max[i]].push_back(r_max[i]);
        }
        if(l_min[i] != 0 && r_min[i] != n + 1) {
            adj[l_min[i]].push_back(r_min[i]);
        }
    }
    bfs(1);
    cout << d[n];
}