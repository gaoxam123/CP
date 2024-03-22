#include <bits/stdc++.h>
using namespace std;

int n, up[1005][23], h[1005], dist[1005], q;
vector <pair <int, int > > adj[1005];

void dfs(int u) {
    for(int i = 0; i < adj[u].size(); i ++) {
        int v = adj[u][i].first;
        if(v == up[u][0]) continue;
        up[v][0] = u;
        dist[v] = dist[u] + adj[u][i].second;
        h[v] = h[u] + 1;
        for(int j = 1; j <= 22; j ++) {
            up[v][j] = up[up[v][j - 1]][j - 1];
        }
        dfs(v);
    }
}

int lca(int u, int v) {
    if(h[u] != h[v]) {
        if(h[u] < h[v]) swap(u, v);
        int k = h[u] - h[v];
        for(int j = 0; (1 << j) <= k; j ++) {
            if((k >> j) & 1) u = up[u][j];
        }
    }
    if(u == v) return u;
    int k = __lg(h[u]);
    for(int j = k; j >= 0; j --) {
        if(up[u][j] != up[v][j]) {
            u = up[u][j];
            v = up[v][j];
        }
    }
    return up[u][0];
}

int solve(int u, int v) {
    int p = lca(u, v);
    return dist[u] + dist[v] - 2 * dist[p];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    for(int i = 1; i < n; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    h[1] = 1;
    up[1][0] = 1;
    dfs(1);

    while(q --) {
        int u, v;
        cin >> u >> v;
        cout << solve(u, v) << endl;
    }
}