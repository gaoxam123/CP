// https://oj.vnoi.info/problem/olp_ct22_roadimpro
#include <bits/stdc++.h>
using namespace std;

int q, n, m, s, t0, d[2005][2][2005], max_edge;
vector <pair <int, int> > adj[2005];

struct gg {
    int cost, node, used;
    gg(int _cost, int _node, int _used) {
        cost = _cost, node = _node, used = _used;
    }
    bool operator < (const gg &other) const {
        return cost > other.cost;
    }
};

void dijkstra(int s, int x) {
    priority_queue <gg> pq;
    pq.push({0, s, 0});
    d[s][0][x] = d[s][1][x] = 0;
    while(!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        int u = t.node, cost = t.cost, used = t.used;
        if(cost > d[u][t.used][x]) continue;
        for(auto p: adj[u]) {
            int v = p.second, w = p.first;
            if(d[v][used][x] > d[u][used][x] + w) {
                d[v][used][x] = d[u][used][x] + w;
                pq.push({d[v][used][x], v, used});
            }
            if(used < 1 && d[v][used + 1][x] > d[u][used][x] + x) {
                d[v][used + 1][x] = d[u][used][x] + x;
                pq.push({d[v][used + 1][x], v, used + 1});
            }
        }
    }
}

int main() {
    cin >> n >> m >> q;
    for(int i = 1; i <= m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        max_edge = max(max_edge, w);
    }
    memset(d, 0x3f, sizeof(d));
    for(int i = 1; i < max_edge; i ++) {
        dijkstra(1, i);
    }
    while(q --) {
        cin >> s >> t0;
        if(s == 1) {
            cout << "0" << endl;
            continue;
        }
        if(t0 < max_edge) cout << min(d[s][1][t0], d[s][0][t0]) << endl; 
        else cout << d[s][0][t0] << endl;
    }
}