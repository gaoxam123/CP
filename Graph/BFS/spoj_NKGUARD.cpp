// https://oj.vnoi.info/problem/nkguard
#include <bits/stdc++.h>
using namespace std;

int n, m, a[705][705], ans;
bool visited[705][705];
int moveX[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int moveY[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void bfs(int sx, int sy) {
    int check = 1;
    queue <pair <int, int> > q;
    q.push(make_pair(sx, sy));
    visited[sx][sy] = true;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 8; i ++) {
            int u = x + moveX[i];
            int v = y + moveY[i];

            if(u > n || u < 1) continue;
            if(v > m || v < 1) continue;

            if(!visited[u][v] && a[u][v] == a[x][y]) {
                visited[u][v] = true;
                q.push(make_pair(u, v));
            }
            if(a[x][y] < a[u][v]) check = 0;
        }
    }
    ans += check;
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(!visited[i][j]) bfs(i, j);
        }
    }
    cout << ans;
}