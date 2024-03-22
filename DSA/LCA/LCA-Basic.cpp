#include <bits/stdc++.h>
using namespace std;

int n, up[100005][23], h[100005], q;
vector <int> adj[100005];

void dfs(int u) {
    for (int i = 0; i < adj[u].size(); i ++) {
        int v = adj[u][i];
        if(v == up[u][0]) continue;
        h[v] = h[u] + 1;
        up[v][0] = u;
        for(int j = 1; j <= 20; j ++) {
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
            if(k >> j & 1) u = up[u][j];
        }
    }
    if(u == v) return u;
    int k = __lg(h[u]);
    for(int j = k; j >= 0; j --) {
        if(up[u][j] != up[v][j])
            u = up[u][j], v = up[v][j];
    }
    return up[u][0];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    up[1][0] = 1;
    h[1] = 1;
    dfs(1);
    cin >> q;
    while(q --) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << endl;
    }
    return 0;
}