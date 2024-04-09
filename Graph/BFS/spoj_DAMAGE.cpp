// https://oj.vnoi.info/problem/damage
#include <bits/stdc++.h>
using namespace std;

int p, c, n, cnt;
vector <int> adj[30005];
int a[30005], visited[30005];
map <int, bool> m;

void bfs(int x) {
    queue <int> q;
    q.push(x);
    visited[x] = 1;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v: adj[u]) {
            if(visited[v] == 0 && !m[v]) {
                visited[v] = 1;
                q.push(v);
            }
        }
    }
}

int main() {
    cin >> p >> c >> n;
    for(int i = 1; i <= c; i ++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        for(auto v: adj[a[i]]) {
            m[v] = true;
        }
    }
    int cnt = 0;
    bfs(1);
    for(int i = 1; i <= p; i ++) {
    	if(visited[i] == 1 && !m[i]) cnt ++;
    }
    cout << p - cnt;
}