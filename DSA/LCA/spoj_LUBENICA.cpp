#include <bits/stdc++.h>
using namespace std;

int n, up[100005][23], maxx[100005][23], minn[100005][23], h[100005], q;
vector <pair <int, int> > adj[100005];

void dfs(int u) {
    for(int i = 0; i < adj[u].size(); i ++) {
        pair <int, int> v = adj[u][i];
        if(v.first == up[u][0]) continue;
        up[v.first][0] = u;
        h[v.first] = h[u] + 1;
        maxx[v.first][0] = v.second;
        minn[v.first][0] = v.second;
        for(int j = 0; j <= 20; j ++) {
            up[v.first][j] = up[up[v.first][j - 1]][j - 1];
            maxx[v.first][j] = max(maxx[v.first][j - 1], maxx[maxx[v.first][j - 1]][j - 1]);
            minn[v.first][j] = min(minn[v.first][j - 1], minn[minn[v.first][j - 1]][j - 1]);
        }
        dfs(v.first);
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
    if (u == v) return u;
    int k = __lg(h[u]);
    for(int j = k; j >= 0; j --) {
        if(up[u][j] != up[v][j]) {
            u = up[u][j];
            v = up[v][j];
        }
    }
    return up[u][0];
}

int maxedge(int u, int v) {
    int ans = -1e9;
    for(int j = 20; j >= 0; j --) {
        if(h[up[u][j]] > h[v]) {
            ans = max(ans, maxx[u][j]);
            u = up[u][j];
        }
    }
    return ans;
}

int minedge(int u, int v) {
    int ans = 1e9;
    for(int j = 20; j >= 0; j --) {
        if(h[up[u][j]] > h[v]) {
            ans = min(ans, minn[u][j]);
            u = up[u][j];
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));       
    }
    h[1] = 1;
    up[1][0] = 1;
    cin >> q;
    while(q --) {
        int u, v;
        cin >> u >> v;
        int gg = lca(u, v);
        cout << min(minedge(u, gg), minedge(v, gg)) << " " << max(maxedge(u, gg), maxedge(v, gg)) << endl;
    }
    return 0;
} 