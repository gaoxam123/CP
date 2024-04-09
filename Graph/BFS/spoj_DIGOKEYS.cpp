// https://www.spoj.com/problems/DIGOKEYS/
#include <bits/stdc++.h>
using namespace std;

int t, n, d[100005], visited[100005], par[100005];
vector <int> adj[100005];

void bfs(int x) {
    queue <int> q;
    visited[x] = 1;
    q.push(x);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v: adj[u]) {
            if(!visited[v]) {
                visited[v] = 1;
                d[v] = d[u] + 1;
                par[v] = u;
                q.push(v);
            }
        }
    }
}

int main() {
    cin >> t;
    while(t --) {
        memset(adj, 0, sizeof(adj));
        memset(visited, 0, sizeof(visited));
        memset(d, 0, sizeof(d));
        memset(par, -1, sizeof(par));
        cin >> n;
        for(int i = 1; i < n; i ++) {
            int m;
            cin >> m;
            for(int j = 1; j <= m; j ++) {
                int u;
                cin >> u;
                adj[i].push_back(u);
                // adj[u].push_back(i);
            }
            sort(adj[i].begin(), adj[i].end());
        }
        bfs(1);
        vector <int> path;
        for(int v = n; v != -1; v = par[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());
        if(d[n] == 0) cout << "-1" << endl;
        else {
            cout << d[n] << endl;
            for(auto v: path) {
                cout << v << " ";
            }
            cout << endl;
        }
    }
}