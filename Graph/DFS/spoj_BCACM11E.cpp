// https://www.spoj.com/PTIT/problems/BCACM11E/
#include <bits/stdc++.h>
using namespace std;

int n, t, a[105][105], joint[105], num[105], low[105], timeDFS, par[105];
vector <int> adj[105];

void dfs(int u, int pre) {
    num[u] = low[u] = ++ timeDFS;
    int child = 0;
    for(int v: adj[u]) {
        if(v == pre) continue;
        if(!num[v]) {
            child ++;
            par[v] = u;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(u == pre) {
                if(child > 1) joint[u] = 1;
            }
            else if(low[v] >= num[u]) joint[u] = 1;
        }
        else low[u] = min(low[u], num[v]);
    }
}

int main() {
    cin >> t;
    while(t --) {
        for(int i = 1; i <= 100; i ++) {
            adj[i].clear();
        }
        memset(joint, 0, sizeof(joint));
        memset(par, 0, sizeof(par));
        memset(num, 0, sizeof(num));
        memset(low, 0, sizeof(low));
        timeDFS = 0;
        cin >> n;
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= n; j ++) {
                cin >> a[i][j];
                if(a[i][j] == 1) {
                    adj[i].push_back(j);
                }
            }
        }
        int ans = 0, cnt = 0;
        par[1] = 1;
        dfs(1, 1);
        for(int i = 1; i <= n; i ++) if(joint[i] == 1) cnt ++;
        if(!cnt) cout << "0" << endl;
        else {
            int index = 0;
            for(int i = 1; i <= n; i ++) {
                if(joint[i] == 1) {
                    cnt = 0;
                    for(int v: adj[i]) {
                        if(par[v] == i && low[v] >= num[i]) {
                            cnt ++;
                        }
                    }
                    if(par[i] != i) cnt ++;
                    if(ans < cnt) {
                        ans = cnt;
                        index = i;
                    }
                }
            }
            cout << index << endl;
        } 
    }
}