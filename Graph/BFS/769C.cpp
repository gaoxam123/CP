// https://codeforces.com/contest/769/problem/C
#include <bits/stdc++.h>
using namespace std;

int n, m, k, d[1005][1005];
char a[1005][1005];
pair <int, int> par[1005][1005];
int moveX[] = {1, 0, 0, -1};
int moveY[] = {0, -1, 1, 0};
string step = "DLRU";

void bfs(int sx, int sy) {
    queue <pair <int, int> > q;
    q.push(make_pair(sx, sy));
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i ++) {
            int u = x + moveX[i];
            int v = y + moveY[i];
            if(u > n || u < 1 || v > m || v < 1) continue;
            if(d[u][v] == 1e9 && a[u][v] != '*') {
                d[u][v] = d[x][y] + 1;
                q.push(make_pair(u, v));
            }
        }
    }
}

int main() {
    cin >> n >> m >> k;
    int sx, sy;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> a[i][j];
            d[i][j] = 1e9;
            if(a[i][j] == 'X') {
                sx = i;
                sy = j;
            }
        }
    }
    if(k % 2 != 0) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    d[sx][sy] = 0;
    bfs(sx, sy);
    string ans;
    bool check = true;
    while(k --) {
        bool ok = false;
        for(int i = 0; i < 4; i ++) {
            int u = sx + moveX[i];
            int v = sy + moveY[i];
            if(u > n || u < 1 || v > m || v < 1) continue;
            if(a[u][v] != '*' && d[u][v] <= k) {
                sx = u;
                sy = v;
                ans += step[i];
                ok = true;
                break;
            }
        }
        if(!ok) {
            check = false;
            break;
        }
    }
    if(!check) cout << "IMPOSSIBLE";
    else cout << ans;
}