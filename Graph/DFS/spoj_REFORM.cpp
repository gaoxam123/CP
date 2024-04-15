// https://oj.vnoi.info/problem/reform
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, num[200005], low[200005], timeDFS, bridges, visited[200005], num_cc, ans, sz[200005], par[200005];
vector <int> adj[200005];
vector <pair <int, int> > edges;

void bfs(int x) {
    visited[x] = 1;
    queue <int> q;
    q.push(x);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v: adj[u]) {
            if(!visited[v]) {
                visited[v] = 1;
                q.push(v);
            }
        }
    }
}

void dfs(int u, int pre) {
    num[u] = low[u] = ++ timeDFS;
    sz[u] = 1;
    for(int v: adj[u]) {
        if(v == pre) continue;
        if(!num[v]) {
            dfs(v, u);
            par[v] = u;
            sz[u] += sz[v];
            low[u] = min(low[u], low[v]);
            if(low[v] == num[v]) {
                bridges ++;
                edges.push_back({u, v});
            }
        }
        else low[u] = min(low[u], num[v]);
    }
}

signed main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i ++) {
        if(!visited[i]) {
            bfs(i);
            num_cc ++;
        }
    }
    if(num_cc > 2) {
        cout << "0";
        return 0;
    }
    else if(num_cc == 2) {
        for(int i = 1; i <= n; i ++) {
            if(!num[i]) {
                dfs(i, i);
                break;
            }
        }
        ans = timeDFS * (n - timeDFS);
        for(int i = 1; i <= n; i ++) {
            if(!num[i]) {
                dfs(i, i);
            }
        }
        ans *= (m - bridges);
        cout << ans;
    }
    else {
        dfs(1, 1);
        ans = ((n - 1) * n / 2 - m) * (m - edges.size());
        for(auto x: edges) {
            int u = x.first, v = x.second;
            ans += sz[v] * (n - sz[v]) - 1;
        }
        cout << ans;
    }
}