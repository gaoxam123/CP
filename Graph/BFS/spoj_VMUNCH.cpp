// https://oj.vnoi.info/problem/vmunch
#include <bits/stdc++.h>
using namespace std;

int n, m, d[105][105];
char a[105][105];
bool visited[105][105];
int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void bfs(int sx, int sy) {
    visited[sx][sy] = true;
    queue <pair <int, int> > q;
    q.push(make_pair(sx, sy));
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i ++) {
            int u = x + moveX[i];
            int v = y + moveY[i];
            if(u > n || v > m || u < 1 || v < 1) continue;
            if(!visited[u][v] && a[u][v] != '*') {
                visited[u][v] = true;
                d[u][v] = d[x][y] + 1;
                q.push(make_pair(u, v));
            }
        }
    }
}

int main() {
    int sx, sy, tx, ty;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> a[i][j];
            if (a[i][j] == 'C') { sx = i; sy = j; }
            if (a[i][j] == 'B') { tx = i; ty = j; }
        }
    }
    bfs(sx, sy);
    cout << d[tx][ty];
}