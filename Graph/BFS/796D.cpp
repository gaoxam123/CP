// https://codeforces.com/contest/796/problem/D
#include <bits/stdc++.h>
using namespace std;

int n, k, d, check[300005], visited[300005], cnt;
vector <pair <int, int> > adj[300005];
queue <pair <int, int> > q;

int main() {
    cin >> n >> k >> d;
    for(int i = 1; i <= k; i ++) {
        int u;
        cin >> u;
        q.push({u, 0});
    }
    for(int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    while(!q.empty()) {
        int u = q.front().first;
        int pre = q.front().second;
        q.pop();
        if(visited[u]) continue;
        visited[u] = 1;
        for(int i = 0; i < adj[u].size(); i ++) {
            int v = adj[u][i].first;
            int edge = adj[u][i].second;
            if(v == pre) continue;
            if(visited[v]) check[edge] = 1;
            else q.push({v, u});
        }
    }
    for(int i = 1; i < n; i ++) if(check[i]) cnt ++;
    cout << cnt << endl;
    for(int i = 1; i < n; i ++) if(check[i]) cout << i << " ";
}