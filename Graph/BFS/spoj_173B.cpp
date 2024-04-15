// https://codeforces.com/contest/173/problem/B
#include <bits/stdc++.h>
using namespace std;

int n, m, d[200005], visited[200005];
char a[1005][1005];
vector <int> adj[200005];

void bfs(int x) {
    visited[x] = 1;
    queue <int> q;
    q.push(x);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v: adj[u]) {
            if(!visited[v]) {
                visited[v] = 1;
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> a[i][j];
            if(a[i][j] == '#') {
                adj[i].push_back(j + n);
                adj[j + n].push_back(i);
            }
        }
    }
    bfs(1);
    cout << (d[n] ? d[n] : -1);
}