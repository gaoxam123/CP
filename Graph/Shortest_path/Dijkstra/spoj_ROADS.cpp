#include <bits/stdc++.h>
using namespace std;

int n, m, D, ans, t, k;
int d[105][1000005];

struct dataa {
    int dis, cost, node;
    dataa (int _dis, int _cost, int _node) {
        dis = _dis; cost = _cost; node = _node;
    }
    bool operator < (const dataa &other) const { return dis > other.dis; }
};

vector <dataa> adj[105];
priority_queue <dataa> pq;

void init() {
    for(int i = 0; i <= n; i ++) adj[i].clear();
    ans = 1e9;
    memset(d, 0x3f, sizeof(d));
    while(!pq.empty()) pq.pop();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t --) {
        cin >> k >> n >> m;
        init();
        for (int i = 1; i <= m; i ++) {
            int u, v, l, t;
            cin >> u >> v >> l >> t;
            adj[u].push_back(dataa(l, t, v));
            adj[v].push_back(dataa(l, t, u));
        }
        d[1][0] = 0;
        pq.push(dataa(0, 0, 1));
        while(!pq.empty()) {
            dataa u = pq.top();
            pq.pop();
            if(u.dis > d[u.node][u.cost]) continue;
            if(u.node == n) {
                ans = d[u.node][u.cost];
                break;
            }
            for(int i = 0; i < adj[u.node].size(); i ++){
                int v = adj[u.node][i].node;
                int kc = adj[u.node][i].dis;
                int c = adj[u.node][i].cost;
                if(u.cost + c < k) {
                    if(d[v][u.cost + c] > d[u.node][u.cost] + kc) {
                        d[v][u.cost + c] = d[u.node][u.cost] + kc;
                        pq.push(dataa(d[v][u.cost + c], u.cost + c, v));
                    }
                }
            }
        }
        if (ans != 1e9) cout << ans << endl;
        else cout << "-1" << endl;
    }
    return 0;
}