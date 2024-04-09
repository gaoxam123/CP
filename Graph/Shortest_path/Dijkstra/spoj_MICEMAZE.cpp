// https://www.spoj.com/problems/MICEMAZE/
#include <bits/stdc++.h>
using namespace std;

int n, e, t, cnt, m, d[105];
vector <pair <int, int> > adj[105];
priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair<int, int> > > pq;

int main() {
    cin >> n >> e >> t >> m;
    for(int i = 1; i <= m; i ++) {
        int u, v, dis;
        cin >> u >> v >> dis;
        adj[u].push_back(make_pair(v, dis));
    }
    for(int i = 1; i <= n; i ++) {
        if(i == e) continue;
        while(!pq.empty()) pq.pop();
        memset(d, 1000000, sizeof(d));
        d[i] = 0;
        pq.push(make_pair(0, i));
        while(!pq.empty()) {
            pair <int, int> u = pq.top();
            pq.pop();
            if(u.first > d[u.second]) continue;
            for(auto v: adj[u.second]) {
                if(d[v.first] > d[u.second] + v.second) {
                    d[v.first] = d[u.second] + v.second;
                    pq.push(make_pair(d[v.first], v.first));
                }
            }
        }
        if(d[e] <= t) cnt ++;
    }
    cout << cnt + 1;
}