#include <bits/stdc++.h>
using namespace std;

int n, up[100005][23], h[100005], q;
vector <int> adj[100005];

void dfs(int u) {
    for(int i = 0; i < adj[u].size(); i ++) {
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

int k_ancestor(int u, int k) {
    for(int j = 0; (1 << j) <= k; j ++) {
        if(k >> j & 1) u = up[u][j];
    }
    return u;
}

int dist[100005][23];
vector <pair <int, int> > edge[100005];

void pre_process(int u) {
    for(int i = 0; i < edge[u].size(); i ++) {
        pair <int, int> v = edge[u][i];
        if(v.first == up[u][0]) continue;
        h[v.first] = h[u] + 1;
        up[v.first][0] = u;
        dist[v.first][0] = v.second;
        for(int j = 1; j <= 20; j ++) {
            up[v.first][j] = up[up[v.first][j - 1]][j - 1];
            dist[v.first][j] = dist[dist[v.first][j - 1]][j - 1];
        } 
        dfs(v.first);
    }
}

int cal_dist(int u, int k) {
    int sum = 0;
    for(int j = 0; (1 << j) <= k; j ++) {
        if(k >> j & 1) {
            sum += dist[u][j];
            u = up[u][j];
        }
    }
    return sum;
}

int solve(int u, int x) {
    int lo = 0, hi = h[u], mid, ans = 0;
    while(lo <= hi) {
        mid = (lo + hi) >> 1;
        if(cal_dist(u, mid) <= x) {
            ans = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    return k_ancestor(u, ans);
}

int solve2(int u, int x) {
    int now_dist = 0;
    for(int j = __lg(h[u]); j >= 0; j --) {
        if(h[u] >= (1 << j) && now_dist + dist[u][j] <= x) {
            now_dist += dist[u][j];
            u = up[u][j];
        }       
    }
    return u;
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
        if(up[u][j] != up[v][j]) {
            u = up[u][j];
            v = up[v][j];
            break;
        }
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
    dfs(1);
    
    int q;
    cin >> q;
    while(q --) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << endl;
    }
    return 0;
}