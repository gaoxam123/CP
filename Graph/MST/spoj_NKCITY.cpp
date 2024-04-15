// https://oj.vnoi.info/problem/nkcity
#include <bits/stdc++.h>
using namespace std;

int n, m, up[100005], sz[100005], ans = -1e9;
vector <pair <int, pair <int, int> > > adj;

void init(int u) {
    sz[u] = 1;
    up[u] = u;
}

int find(int u) {
    if(u == up[u]) return u;
    up[u] = find(up[u]);
    return up[u];
}

void onion(int u, int v) {
    u = find(u), v = find(v);
    if(u != v) {
        if(sz[u] < sz[v]) swap(u, v);
        up[v] = u;
        sz[u] += sz[v];
    }
}

bool isSameset(int u, int v) {
    return find(u) == find(v);
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj.push_back({w, {u, v}});
    }
    for(int i = 1; i <= n; i ++) init(i);
    sort(adj.begin(), adj.end());
    for(auto edge: adj) {
        int u = edge.second.first, v = edge.second.second, w = edge.first;
        if(!isSameset(u, v)) {
            onion(u, v);
            ans = max(ans, w);
        }
    }
    cout << ans;
}