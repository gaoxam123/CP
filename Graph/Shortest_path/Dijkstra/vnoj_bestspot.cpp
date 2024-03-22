#include <bits/stdc++.h>
using namespace std;

int n, m, p, d[505][505], f[505];
vector <pair <int, int> > adj[505];
priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > pq;

void dijkstra(int x) {
    d[x][x] = 0;
    pq.push(make_pair(d[x][x], x));
    while(!pq.empty()) {
        pair <int, int> u = pq.top();
        pq.pop();
        if(u.first > d[x][u.second]) continue;
        for(pair <int, int> v:adj[u.second]) {
            if(d[x][v.first] > d[x][u.second] + v.second) {
                d[x][v.first] = d[x][u.second] + v.second;
                pq.push(make_pair(d[x][v.first], v.first));
            }
        }
    }
}

int main() {
    for(int i = 1; i < 505; i ++) 
        for(int j = 1; j < 505; j ++) 
            d[i][j] = 1e9;
    cin >> p >> n >> m;
    for(int i = 0; i < n; i ++) cin >> f[i];
    for(int i = 0; i < m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));    
    }
    int ans = 1e9;
    int pos = 0;
    for(int i = 1; i <= p; i ++) dijkstra(i);
    for(int i = 1; i <= p; i ++) {
        int sum = 0;
        for(int j = 0; j < n; j ++) {
            sum += d[i][f[j]];
        }
        if(ans > sum) {
            ans = sum;
            pos = i;
        }
    }
    cout << pos;
}