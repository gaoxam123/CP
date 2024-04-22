// https://oj.vnoi.info/problem/centre28
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, s, t, ds[100005], dt[100005], cs[100005], ct[100005];
vector <pair <int, int> > adj[100005];
// vector <int> new_edges[100005];
vector <int> ans;

void dijkstra(int x, int d[], int c[]) {
    priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > pq;
    pq.push({0, x});
    d[x] = 0;
    c[x] = 1;
    while(!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        int u = t.second, cost = t.first;
        if(cost > d[u]) continue;
        for(auto p: adj[u]) {
            int v = p.second, w = p.first;
            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
                c[v] = c[u];
                pq.push({d[v], v});
            }
            else if(d[v] == d[u] + w) {
                c[v] += c[u];
            }
        }
    }
}

// bool visited[100005];
// map <int, int> mp;

// void bfs(int x) {
//     queue <int> q;
//     visited[x] = 1;
//     q.push(x);
//     while(!q.empty()) {
//         int u = q.front();
//         q.pop();
//         for(auto p: adj[u]) {
//             int v = p.second;
//             if(!mp[v] && !visited[v]) {
//                 visited[v] = 1;
//                 new_edges[u].push_back(v);
//                 new_edges[v].push_back(u);
//                 q.push(v);
//             }
//         }
//     }
// }

// int num[100005], low[100005], timeDFS, joint[100005];

// void dfs(int u, int pre) {
//     num[u] = low[u] = ++ timeDFS;
//     for(int v: new_edges[u]) {
//         if(v == pre) continue;
//         if(!num[v]) {
//             dfs(v, u);
//             low[u] = min(low[u], low[v]);
//             if(low[v] >= num[u]) {
//                 if(u != pre) joint[u] = 1;
//             }
//         }
//         else low[u] = min(low[u], num[v]);
//     }
// }

signed main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    memset(ds, 0x3f, sizeof(ds));
    memset(dt, 0x3f, sizeof(dt));
    dijkstra(1, ds, cs);
    dijkstra(n, dt, ct);
    for(int i = 1; i <= n; i ++) {
        if(!(ds[i] + dt[i] == ds[n] && cs[i] * ct[i] == cs[n])) ans.push_back(i);
    }   
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(int i: ans) cout << i << endl;
}