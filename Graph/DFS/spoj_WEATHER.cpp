// https://oj.vnoi.info/problem/weather
#include <bits/stdc++.h>
using namespace std;

int n, m, sz[105], num[105], low[105], timeDFS, ans;
vector <int> adj[105];

void dfs(int u, int pre) {
    sz[u] = 1;
    num[u] = low[u] = ++timeDFS;
    for(auto v: adj[u]) {
        if(v == pre) continue;
        if(!num[v]) {
            dfs(v, u);
            sz[u] += sz[v];
            low[u] = min(low[u], low[v]);
        }
        else low[u] = min(low[u], num[v]);
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    for(int i = 2; i <= n; i ++) {
        if(low[i] == num[i]) ans += sz[i] * (n - sz[i]);
    }
    cout << ans;
}