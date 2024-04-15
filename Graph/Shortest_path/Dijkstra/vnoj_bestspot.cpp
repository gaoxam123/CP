// https://oj.vnoi.info/problem/bestspot
#include <bits/stdc++.h>
using namespace std;

int n, m, p, d[505][505], a[505];
vector <pair <int, int> > adj[505];
priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > pq;

void dijkstra(int x) {
    d[x][x] = 0;
    pq.push({0, x});
    while(!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        int u = t.second;
        int cost = t.first;
        if(cost > d[u][x]) continue;
        for(auto p: adj[u]) {
            int v = p.second, w = p.first;
            if(d[v][x] > d[u][x] + w) {
                d[v][x] = d[u][x] + w;
                pq.push({d[v][x], v});
            }
        } 
    }
}

int main() {
    cin >> p >> n >> m;
    memset(d, 0x3f, sizeof(d));
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    int ans = 1e9;
    int pos = 0;
    for(int i = 1; i <= p; i ++) dijkstra(i);
    for(int i = 1; i <= p; i ++) {
        int sum = 0;
        for(int j = 1; j <= n; j ++) {
            sum += d[i][a[j]];
        }
        if(ans > sum) {
            ans = sum;
            pos = i;
        }
    }
    cout << pos;
}