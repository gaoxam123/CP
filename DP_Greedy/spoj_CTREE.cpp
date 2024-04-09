// https://oj.vnoi.info/problem/ctree
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, ans[10005], dp[10005][21];
vector <int> adj[10005];

void dfs(int p, int u) {
    for(int i = 1; i <= 20; i ++) dp[u][i] = i;
    for(auto v: adj[u]) {
        if(v == p) continue;
        dfs(u, v);
        for(int i = 1; i <= 20; i ++) {
            int x = 1e18;
            for(int j = 1; j <= 20; j ++) {
                if(i != j) x = min(x, dp[v][j]);
            }
            dp[u][i] += x;
        }
    }
}

void find(int p, int u) {
    for(auto v: adj[u]) {
        if(v == p) continue;
        for(ans[v] = 1; ans[v] <= 20; ans[v] ++) {
            if(ans[v] != ans[u]) break;
        }
        for(int i = 1; i <= 20; i ++) {
            if(i != ans[u] && dp[v][i] < dp[v][ans[v]]) ans[v] = i;
        }
        find(u, v);
    }
}

signed main() {
    cin >> n;
    for(int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, 1);
    ans[1] = 1;
    for(int i = 2; i <= 20; i ++) {
        if(dp[1][i] < dp[1][ans[1]]) ans[1] = i;
    }
    find(0, 1);
    cout << dp[1][ans[1]] << endl;
    for(int i = 1; i <= n; i ++) cout << ans[i] << endl;
}