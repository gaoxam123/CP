// https://oj.vnoi.info/problem/usaco18dg_dining
#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector <pair <int, int> > adj[50005];
vector <pair <int, int> > co;

void dijkstra(int x, vector <int> &d) {
    priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > pq;
    d[x] = 0;
    pq.push({0, x});
    while(!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        int u = t.second, cost = t.first;
        if(cost > d[u]) continue;
        for(auto p: adj[u]) {
            int v = p.second, w = p.first;
            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }
}

int main() {
    cin >> n >> m >> k;
    co.resize(k + 10);
    for(int i = 1; i <= m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    for(int i = 1; i <= k; i ++) {
        int a, b;
        cin >> a >> b;
        co[i] = {a, b};
    }
    vector <int> d1, d2;
    d1.resize(n + 5);
    d2.resize(n + 5);
    for(int i = 1; i <= n + 1; i ++) d1[i] = d2[i] = 1e9;
    dijkstra(n, d1);
    for(int i = 1; i <= k; i ++) {
        int u = co[i].first, w = co[i].second, d = d1[u];
        // adj[u].push_back({d - w, n + 1});
        adj[n + 1].push_back({d - w, u});
    }
    dijkstra(n + 1, d2);
    int ans = 0;
    for(int i = 1; i < n; i ++) {
        if(d2[i] <= d1[i]) cout << "1" << endl;
        else cout << "0" << endl;
    }
}