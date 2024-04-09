// https://www.spoj.com/problems/NATALIAG/
#include <bits/stdc++.h>
using namespace std;

int t, m, n, d[205][105];
char a[205][105];
bool visited[205][105];
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
            if(u > m || v > n || u < 1 || v < 1) continue;
            if(!visited[u][v] && a[u][v] != '*') {
                visited[u][v] = true;
                d[u][v] = d[x][y] + 1;
                q.push(make_pair(u, v));
            }
        }
    }
}

int main() {
    cin >> t;
    while(t --) {
        memset(visited, false, sizeof(visited));
        memset(d, 0, sizeof(d));
        cin >> m >> n;
        int sx, sy, tx, ty;
        for(int i = 1; i <= m; i ++) {
            for(int j = 1; j <= n; j ++) {
                cin >> a[i][j];
                if(a[i][j] == '$') {
                    sx = i;
                    sy = j;
                }
                if(a[i][j] == '#') {
                    tx = i;
                    ty = j;
                }
            }
        }
        bfs(sx, sy);
        if(d[tx][ty] > 0) cout << d[tx][ty] << endl;
        else cout << "-1" << endl;
    }
}