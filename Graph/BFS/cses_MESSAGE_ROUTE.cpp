// https://cses.fi/problemset/task/1667/
#include <bits/stdc++.h>
using namespace std;

int n, m, visited[100005], d[100005], par[100005];
vector <int> adj[100005];
vector <int> ans;

void bfs(int x) {
    queue <int> q;
    q.push(x);
    visited[x] = 1;
    par[x] = -1;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v: adj[u]) {
            if(!visited[v]) {
                visited[v] = 1;
                par[v] = u;
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
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
    bfs(1);
    if(!d[n]) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    cout << d[n] + 1 << endl;
    for(int u = n; u != -1; u = par[u]) {
        ans.push_back(u);
    }
    reverse(ans.begin(), ans.end());
    for(auto u: ans) cout << u << " ";
}