// https://codeforces.com/problemset/problem/1433/G
#include <bits/stdc++.h>
using namespace std;

int n, m, k, d[1005][1005];
vector <pair <int, int> > adj[1005];
pair <int, int> routes[1005];
pair <int, int> edges[1005];

void dijkstra(int x) {
    priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > pq;
    d[x][x] = 0;
    pq.push({0, x});
    while(!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        int u = t.second, cost = t.first;
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
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i].first = u, edges[i].second = v;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    memset(d, 0x3f, sizeof(d));
    for(int i = 1; i <= n; i ++) dijkstra(i);
    int ans = 0;
    for(int i = 1; i <= k; i ++) {
        cin >> routes[i].first >> routes[i].second;
        ans += d[routes[i].first][routes[i].second];
    }
    for(int i = 1; i <= m; i ++) {
        int u = edges[i].first, v = edges[i].second;
        int sum = 0;
        for(int i = 1; i <= k; i ++) {
            sum += min({d[routes[i].first][u] + d[v][routes[i].second], d[routes[i].first][v] + d[u][routes[i].second], d[routes[i].first][routes[i].second]});
        }
        ans = min(ans, sum);
    }
    cout << ans;
}