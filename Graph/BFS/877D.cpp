// https://codeforces.com/contest/877/problem/D
#include <bits/stdc++.h>
using namespace std;

int n, m, d[1005][1005], k;
char a[1005][1005];
int moveX[] = {1, -1, 0, 0};
int moveY[] = {0, 0, 1, -1};

int main() {
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }
    }
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            d[i][j] = 1e9;
        }
    }
    queue <pair <int, int> > q;
    q.push({sx, sy});
    d[sx][sy] = 0;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        if(x == tx && y == ty) {
            cout << d[tx][ty];
            return 0;
        }
        q.pop();
        for(int i = 0; i < 4; i ++) {
            for(int j = 1; j <= k; j ++) {
                int u = x + moveX[i] * j;
                int v = y + moveY[i] * j;
                if(u < 1 || v < 1 || u > n || v > m) break;
                if(a[u][v] == '#' || d[u][v] <= d[x][y]) break;
                if(d[u][v] > d[x][y] + 1) {
                    d[u][v] = d[x][y] + 1;
                    q.push({u, v});
                }
            }
        }
    }
    cout << "-1";
}