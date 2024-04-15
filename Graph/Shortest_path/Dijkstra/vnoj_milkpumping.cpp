// https://oj.vnoi.info/problem/usaco19dg_pump
#include <bits/stdc++.h>
using namespace std;

int n, m;
float d[1005];

struct gg1 {
    int node, sum_weight, min_size;
    float value;
    gg1(int _node, int _sum_weight, int _min_size, float _value) {
        node = _node, sum_weight = _sum_weight, min_size = _min_size, value = _value;
    }
    bool operator < (const gg1 &other) const {
        return value > other.value;
    }
};

struct gg2 {
    int node, weight, size;
    gg2(int _node, int _weight, int _size) {
        node = _node, weight = _weight, size = _size;
    }
};

vector <gg2> adj[1005];
priority_queue <gg1> pq;

int main() {    
    cin >> n >> m;
    for(int i = 1; i <= m; i ++) {
        int u, v, w, s;
        cin >> u >> v >> w >> s;
        adj[u].push_back({v, w, s});
        adj[v].push_back({u, w, s});
    }
    d[1] = 0;
    pq.push(gg1(1, 0, 1e9, 0));
    while(!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        int u = t.node;
        float value = t.value;
        if(value > d[u]) continue;
        for(auto p: adj[u]) {
            int v = p.node, weight = p.weight, sz = p.size;
            if(d[v] < (double) min(sz, t.min_size) / (t.sum_weight + weight)) {
                d[v] = (double) min(sz, t.min_size) / (t.sum_weight + weight);
                pq.push({v, t.sum_weight + weight, min(sz, t.min_size), d[v]});
            }
        }
    }
    cout << (int) (d[n] * 1000000);
}