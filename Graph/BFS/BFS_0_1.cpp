// https://vjudge.net/problem/CodeChef-REVERSE
#include <bits/stdc++.h>
using namespace std;

int n, m, d[100005];
vector <pair <int, int> > adj[100005];

// main idea: use deque instead of queue, if w == 0, push v to the front so that the queue contains elements with increasing distances

void bfs(int x) {
    memset(d, 1e9, sizeof(d));
    deque <int> q;
    q.push_front(x);
    d[x] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop_front();
        if(u == n) return;
        for(auto edge: adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
                if(w) q.push_back(v);
                else q.push_front(v);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, 0});
        adj[v].push_back({u, 1});
    }
    bfs(1);
    cout << d[n];
}