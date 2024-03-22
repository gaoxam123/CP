// https://codeforces.com/problemset/problem/1946/C
#include <bits/stdc++.h>
using namespace std;

int t, n, k, mid, cnt;
vector<int> adj[100005];
int sz[100005], par[100005];

void dfs(int u) {
    sz[u] = 1;
    for(auto v: adj[u]) {
        if(v != par[u]) {
            par[v] = u;
            dfs(v);
            sz[u] += sz[v];
        }
    }
    if(sz[u] >= mid) {
        cnt ++;
        sz[u] = 0;
    }
}

int main() {
    cin >> t;
    while(t --) {
        cin >> n >> k;
        for(int i = 1; i <= n; i ++)
            adj[i].clear();
        for(int i = 1; i < n; i ++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int l = 1, r = n;
        while(l < r) {
            mid = (l + r + 1) / 2;
            cnt = 0;
            dfs(1);
            if(cnt >= k + 1) {
                l = mid;
            }
            else {
                r = mid - 1;
            }
        }
        cout << l << endl;
    }
}