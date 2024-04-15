// https://oj.vnoi.info/problem/qbschool
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, d[5005], dp[5005];
vector <pair <int, int> > adj[5005];
priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > pq;

signed main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i ++) {
        int k, u, v, w;
        cin >> k >> u >> v >> w;
        adj[u].push_back({v, w});
        if(k == 2) adj[v].push_back({u, w});
    }
    for(int i = 1; i <= n; i ++) d[i] = 1e18;
    dp[1] = 1;
    d[1] = 0;
    pq.push({0, 1});
    while(!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        int u = t.second, dis = t.first;
        if(dis > d[u]) continue;
        if(u == n) break;
        for(auto p: adj[u]) {
            int v = p.first, w = p.second;
            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
                dp[v] = dp[u];
                pq.push({d[v], v});
            } 
            else if(d[v] == d[u] + w) {
                dp[v] += dp[u];
            }
        }
    }
    cout << d[n] << " " << dp[n];
}