#include <bits/stdc++.h>
using namespace std;

int par[100005], n, m, ans;
vector <pair <int, pair <int, int> > > edge;

void init(int n) {
    for(int i = 1; i <= n + 1; i ++) {
        par[i] = i;
    }
}

int find (int u) {
    if(u == par[u]) return u;
    return par[u] = find(par[u]);
}

bool issameset(int u, int v) {
    u = find(u);
    v = find(v);
    return u == v;
}

void Union(int u, int v) {
    if(!issameset(u, v)) {
        u = find(u); 
        v = find(v);
        par[v] = u;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    init(n);
    for(int i = 0; i < m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge.push_back(make_pair(w, make_pair(u, v)));
    }
    sort(edge.begin(), edge.end());
    for(int i = 0; i < m; i ++){
        pair <int, pair <int, int> > gg = edge[i];
        if (!issameset(gg.second.first, gg.second.second)) {
            Union(gg.second.first, gg.second.second);
            ans += gg.first;
        }
    }
    cout << ans;
    return 0;
}