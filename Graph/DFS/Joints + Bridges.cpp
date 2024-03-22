#include <bits/stdc++.h>
using namespace std;

int n, m, low[100005], num[100005], bridge, Time, ans;
bool joint[100005];
vector <int> adj[100005];

void dfs(int u, int pre){
    num[u] = low[u] = ++Time;
    int child = 0;
    for(int i = 0; i < adj[u].size(); i ++){
        int v = adj[u][i];
        if(v == pre) continue;
        if(!num[v]){
            child ++;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(u == pre) 
                if(child > 1) joint[u] = true;
            else if(low[v] >= num[u]) joint[u] = true;
            if(low[v] == num[v]) bridge ++;
        }
        else low[u] = min(low[u], num[v]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n; i ++){
        if(!num[i]) dfs(i, i);
    }
    for (int i = 1;i <= n; i ++) ans += joint[i];

    cout << ans << ' ' << bridge;
    return 0;
}