// https://oj.vnoi.info/problem/netaccel
#include <bits/stdc++.h>
using namespace std;

int n, m, k;
double d[1005][15];

struct gg {
    double cost;
    int node, num;
    gg(double _cost, int _node, int _num) {
        cost = _cost, node = _node, num = _num;
    }
    bool operator < (const gg &other) const {
        return cost > other.cost;
    }
};

priority_queue <gg> pq;
vector <pair <double, int> > adj[1005];

int main() {
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i ++) {
        int u, v;
        double w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    for(int i = 0; i <= 1001; i ++){
		for(int j = 0; j <= 1001; j ++){
			d[i][j] = 1e9 + 7;
		}
	}
    d[1][0] = 0.00;
    pq.push({0.00, 1, 0});
    while(!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        int u = t.node;
        double cost = t.cost;
        int used = t.num;
        if(cost > d[u][used]) continue;
        if(u == n) {
            cout << fixed << setprecision(2) << d[u][used];
            return 0;
        }
        for(auto p: adj[u]) {
            int v = p.second;
            double w = p.first;
            if(d[v][used] > d[u][used] + w) {
                d[v][used] = d[u][used] + w;
                pq.push({d[v][used], v, used});
            }
            double half = 1.00;
            for(int i = 1; i <= k - used; i ++) {
                half *= 2;
                if(d[v][used + i] > d[u][used] + w / half) {
                    d[v][used + i] = d[u][used] + w / half;
                    pq.push({d[v][used + i], v, used + i});
                }
            }
        }
    }
}