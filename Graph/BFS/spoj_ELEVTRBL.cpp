// https://www.spoj.com/problems/ELEVTRBL/
#include <bits/stdc++.h>
using namespace std;

int f, s, g, up, down;
vector <int> adj[1000005];
int d[1000005], visited[1000005];

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
    cin >> f >> s >> g >> up >> down;
    for(int i = 1; i <= f; i ++) {
        if(i + up <= f) {
            adj[i].push_back(i + up);
        }
        if(i - down >= 1) {
            adj[i].push_back(i - down);
        }
    }
    bfs(s);
    if(d[g] == 0 && s != g) cout << "use the stairs";
    else cout << d[g];
}