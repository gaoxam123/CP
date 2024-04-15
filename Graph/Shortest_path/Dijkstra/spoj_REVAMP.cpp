// https://oj.vnoi.info/problem/revamp
#include <bits/stdc++.h>
using namespace std;

int n, m, k, d[10005][25];

struct gg {
    int cost, node, num;
    // min distance to the first node, current node, number of roads fixed
    gg(int _cost, int _node, int _num) {
        cost = _cost, node = _node, num = _num;
    }
    bool operator < (const gg &other) const {
        return cost > other.cost;
    }
};
priority_queue <gg> pq;
vector <pair <int, int> > adj[10005];

int main() {
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    memset(d, 0x3f, sizeof(d));
    d[1][0] = 0;
    pq.push({0, 1, 0});
    while(!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        if(t.cost > d[t.node][t.num]) continue;
        if(t.node == n) {
            cout << d[t.node][t.num];
            return 0;
        }
        for(auto p: adj[t.node]) {
            int v = p.second, w = p.first;
            // not remove track uv
            if(d[v][t.num] > d[t.node][t.num] + w) {
                d[v][t.num] = d[t.node][t.num] + w;
                pq.push({d[v][t.num], v, t.num});
            }
            // remove track uv
            if(t.num < k && d[v][t.num + 1] > d[t.node][t.num]) {
                d[v][t.num + 1] = d[t.node][t.num];
                pq.push({d[v][t.num + 1], v, t.num + 1});
            }
        }
    }
}