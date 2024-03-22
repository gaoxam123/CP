#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n, m;
vector <int> adj[100005];
int up[N][23], h[N];

void dfs(int u) {
    for(int i = 0; i < adj[u].size(); i ++) {
        int v = adj[u][i];
        if(v == up[u][0]) continue;
        up[v][0] = u;
        h[v] = h[u] + 1;
        
        for(int j = 1; j < 23; j ++) {
            up[v][j] = up[up[v][j - 1]][j - 1];
        }
        dfs(v);
    }
}

