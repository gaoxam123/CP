// https://oj.vnoi.info/problem/safenet2
#include <bits/stdc++.h>
using namespace std;

int n, m, num[30005], low[30005], timeDFS, ans = 1;
vector <int> adj[30005];
stack <pair <int, int> > st;

void dfs(int u, int pre) {
    num[u] = low[u] = ++ timeDFS;
    for(int v: adj[u]) {
        if(v == pre) continue;
        if(!num[v]) {
            st.push({u, v});
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] >= num[u]) {
                int cnt = 1;
                while(true) {
                    auto p = st.top();
                    st.pop();
                    cnt ++;
                    if(p == make_pair(u, v)) break;
                }
                ans = max(ans, cnt);
            }
        }   
        else low[u] = min(low[u], num[v]);
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i ++) dfs(i, i);
    cout << ans;
}