// https://oj.vnoi.info/problem/nkguard
#include <bits/stdc++.h>
using namespace std;

int n, m, a[705][705], ans;
bool visited[705][705];
int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void bfs(int sx, int sy) {
    queue <pair <int, int> > q;
    q.push(make_pair(sx, sy));
    visited[sx][sy] = true;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        int cnt = 0;
        for(int i = 0; i < 4; i ++) {
            int u = x + moveX[i];
            int v = y + moveY[i];

            if(u > n || u < 1) continue;
            if(v > m || v < 1) continue;

            if(a[u][v] > a[x][y]) cnt ++;
            if(!visited[u][v]) {
                visited[u][v] = true;
                q.push(make_pair(u, v));
            }
        }
        if(cnt == 0) ans ++;
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }
    }
    bfs(1, 1);
    cout << ans;
}