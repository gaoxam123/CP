// https://oj.vnoi.info/problem/TRAFFICN
#include <bits/stdc++.h>
using namespace std;

int n, m, s, t, k, ds[10005], dt[10005], q;
vector <pair <int, int> > adjs[10005];
vector <pair <int, int> > adjt[10005];

void dijkstra(int x, vector <pair <int, int> > adj[], int d[]) {
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
    cin >> q;
    while(q --) {
        for(int i = 0; i <= 10001; i ++) {
            adjs[i].clear();
            adjt[i].clear();
        }
        cin >> n >> m >> k >> s >> t;
        for(int i = 1; i <= m; i ++) {
            int u, v, w;
            cin >> u >> v >> w;
            adjs[u].push_back({w, v});
            adjt[v].push_back({w, u});
        }
        for(int i = 0; i <= 10001; i ++) ds[i] = dt[i] = 1e9;

        dijkstra(s, adjs, ds);
        dijkstra(t, adjt, dt);

        int ans = ds[t];
        for(int i = 1; i <= k; i ++) {
            int u, v, w;
            cin >> u >> v >> w;
            ans = min(ans, min(ds[u] + w + dt[v], ds[v] + w + dt[u]));
        }
        if(ans != 1e9) cout << ans << endl;
        else cout << "-1" << endl;
    }
}