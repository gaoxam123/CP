// https://oj.vnoi.info/problem/critical
#include <bits/stdc++.h>
using namespace std;

int n, m, sz[20005], num[20005], low[20005], timeDFS, joint[20005], root[20005], par[20005];
double ans;
vector <int> adj[20005];
vector <int> indices;

void dfs(int u, int pre, int r) {
    root[u] = r;
    num[u] = low[u] = ++ timeDFS;
    sz[u] = 1;
    int child = 0;
    for(auto v: adj[u]) {
        if(v == pre) continue;
        if(!num[v]) {
            child ++;
            par[v] = u;
            dfs(v, u, r);
            sz[u] += sz[v];
            low[u] = min(low[u], low[v]);
            if(u == pre) {
                if(child > 1) {
                    joint[u] = 1;
                }
            }
            else if(low[v] >= num[u]) {
                joint[u] = 1;
            }
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
    for(int i = 1; i <= n; i ++) {
        if(!num[i]) {
            dfs(i, i, i);
        }
    }
    for(int i = 1; i <= n; i ++) {
        if(joint[i] == 1) {
            int total_sz = sz[root[i]] - 1;
            int sum = 0;
            for(int v: adj[i]) {
                if(par[v] == i && low[v] >= num[i]) {
                    ans += sz[v] * (total_sz - sz[v]);
                    total_sz -= sz[v];
                    sum += sz[v];
                    
                }
            }
        }
    }
    cout << fixed << setprecision(2) << ans / n;
}