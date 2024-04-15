// https://www.spoj.com/problems/KATHTHI/
#include <bits/stdc++.h>
using namespace std;

int t, n, m, d[1005][1005];
char a[1005][1005];
int moveX[] = {1, -1, 0, 0};
int moveY[] = {0, 0, 1, -1};

void bfs(int sx, int sy) {
    memset(d, 10000000, sizeof(d));
    deque <pair <int, int> > q;
    q.push_back({sx, sy});
    d[sx][sy] = 0;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop_front();
        if(x == n && y == m) return;
        for(int i = 0; i < 4; i ++) {
            int u = x + moveX[i];
            int v = y + moveY[i];
            if(u < 1 || v < 1 || u > n || v > m) continue;
            int w;
            if(a[u][v] == a[x][y]) w = 0;
            else w = 1;
            if(d[u][v] > d[x][y] + w) {
                d[u][v] = d[x][y] + w;
                if(w) q.push_back({u, v});
                else q.push_front({u, v});
            }
        }
    }
}

int main() {
    cin >> t;
    while(t --) {
        cin >> n >> m;
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= m; j ++) {
                cin >> a[i][j];
            }
        }
        bfs(1, 1);
        cout << d[n][m] << endl;
    }
}