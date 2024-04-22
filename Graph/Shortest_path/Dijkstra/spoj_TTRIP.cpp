// https://vn.spoj.com/problems/TTRIP/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, a[105][105], d[105][105], dd[105];
vector <pair <int, int> > adj[105];
map <pair <int, int>, bool> m; 

void dijkstra(int s) {
    priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > pq;
    pq.push({0, s});
    d[s][s] = 0;
    while(!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        int u = t.second, cost = t.first;
        if(cost > d[s][u]) continue;
        for(auto p: adj[u]) {
            int v = p.second, w = p.first;
            if(d[s][v] > d[s][u] + w) {
                d[s][v] = d[s][u] + w;
                pq.push({d[s][v], v});
            }
        }
    }
}

signed main() {
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            cin >> a[i][j];
            if(i != j && a[i][j] != 0) {
                if(!m[{i, j}] && !m[{j, i}]) {
                    m[{i, j}] = m[{j, i}] = true;
                    adj[i].push_back({a[i][j], j});
                    adj[j].push_back({a[i][j], i});
                }
            }
        }
    }
    memset(d, 0x3f, sizeof(d));
    for(int i = 1; i <= n; i ++) {
        dijkstra(i);
    }   
    int ans = 0;
    int s = 1, t = 0;
    for(int i = 1; i <= n - 2; i ++) {
        dd[s] = 1;
        int mn = 1e18;
        for(int u = 1; u <= n - 1; u ++) {
            if(!dd[u] && mn > d[s][u]) {
                mn = d[s][u];
                t = u;
            }
        }
        ans += mn;
        s = t;
    }
    ans += d[t][n];
    cout << ans;
}