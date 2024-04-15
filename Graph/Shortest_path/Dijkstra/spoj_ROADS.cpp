// https://oj.vnoi.info/problem/roads
#include <bits/stdc++.h>
using namespace std;

int t, k, n, m, d[105][10005], ans;

struct gg {
    int dis, node, cost;
    gg(int _dis, int _node, int _cost) {
        dis = _dis, node = _node, cost = _cost;
    }
    bool operator < (const gg &other) const {
        return dis > other.dis;
    }
};

priority_queue <gg> pq;
vector <gg> adj[105];

void init() {
    for(int i = 0; i <= n; i ++) adj[i].clear();
    memset(d, 0x3f, sizeof(d));
    ans = 1e9;
    while(!pq.empty()) {
        pq.pop();
    }
}

int main() {
    cin >> t;
    while(t --) {
        cin >> k >> n >> m;
        init();
        for(int i = 1; i <= m; i ++) {
            int u, v, dis, cost;
            cin >> u >> v >> dis >> cost;
            adj[u].push_back({dis, v, cost});
        }
        d[1][0] = 0;
        pq.push({0, 1, 0});
        while(!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            int u = t.node, dis = t.dis, cost = t.cost;
            if(dis > d[u][cost]) continue;
            if(u == n) {
                ans = d[u][cost];
                break;
            }
            for(auto p: adj[u]) {
                int v = p.node, v_dis = p.dis, c = p.cost;
                if(c + cost <= k) {
                    if(d[v][cost + c] > d[u][cost] + v_dis) {
                        d[v][cost + c] = d[u][cost] + v_dis;
                        pq.push({d[v][cost + c], v, cost + c});
                    }
                }
            }
        }
        if(ans == 1e9) cout << "-1" << endl;
        else cout << ans << endl;
    }
}