//https://codeforces.com/contest/1941/problem/G
#include <bits/stdc++.h>
using namespace std;

int t, n, m;

int main() {
    cin >> t;
    while(t --) {
        map<int, vector<int> > adj;
        queue<int> q;
        map<int, int> d;
        int b, e;
        
        cin >> n >> m;
        for(int i = 1; i <= m; i ++) {
            int u, v, c;
            cin >> u >> v >> c;
            adj[n + c + 1].push_back(v);
            adj[u].push_back(n + c + 1);
            adj[n + c + 1].push_back(u);
            adj[v].push_back(n + c + 1);
        }
        cin >> b >> e;

        q.push(b);
        d[b] = 0;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(auto v: adj[u]) {
                if(d.count(v)) continue;
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
        cout << d[e] / 2 << endl;
    }
}