// https://leetcode.com/problems/find-edges-in-shortest-paths/description/
#include <bits/stdc++.h>
using namespace std;

int n, m, d1[50005], d2[50005];
vector <pair <int, int> > adj[50005];
pair <int, pair <int, int> > edges[50005];
// bool check[50005];

void dijkstra(int x, int d[]) {
    d[x] = 0;
    priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > pq;
    pq.push({0, x});
    while(!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        int u = t.second, cost = t.first;
        if(cost > d[u]) continue;
        for(auto p: adj[u]) {
            int v = p.second, w = p.first;
            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
        edges[i] = {w, {u, v}};
    }
    memset(d1, 0x3f, sizeof(d1));
    memset(d2, 0x3f, sizeof(d2));
    dijkstra(0, d1);
    dijkstra(n - 1, d2);
    for(int i = 1; i <= m; i ++) {
        int w = edges[i].first, u = edges[i].second.first, v = edges[i].second.second;
        if(d1[u] + w + d2[v] == d1[n - 1] || d1[v] + w + d2[u] == d1[n - 1]) {
            cout << "true" << endl;
        }
        else cout << "false" << endl;
    }
}