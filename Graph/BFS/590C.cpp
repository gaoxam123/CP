// https://codeforces.com/problemset/problem/590/C
#include <bits/stdc++.h>
using namespace std;

int n, m, d[4][1005][1005];
char a[1005][1005];
int moveX[] = {1, -1, 0, 0};
int moveY[] = {0, 0, 1, -1};

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            d[0][i][j] = d[1][i][j] = d[2][i][j] = 1e9;
        }
    }
    for(int c = '1'; c <= '3'; c ++) {
        deque <pair <int, int> > q;
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= m; j ++) {
                if(a[i][j] == c) {
                    d[c - '1'][i][j] = 0;
                    q.push_back({i, j});
                }
            }
        }
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop_front();
            for(int i = 0; i < 4; i ++) {
                int u = x + moveX[i];
                int v = y + moveY[i];
                if(u < 1 || v < 1 || u > n || v > m || a[u][v] == '#') continue;
                int w = 0;
                if(a[u][v] == '.') w = 1;
                if(d[c - '1'][u][v] > d[c - '1'][x][y] + w) {
                    d[c - '1'][u][v] = d[c - '1'][x][y] + w;
                    if(w) q.push_back({u, v});
                    else q.push_front({u, v});
                }
            }
        }
    }
    int ans = -1;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(d[0][i][j] != 1e9 && d[1][i][j] != 1e9 && d[2][i][j] != 1e9) {
                int w = 0;
                if(a[i][j] == '.') w = 1;
                int cost = d[0][i][j] + d[1][i][j] + d[2][i][j] - 2 * w;
                if(ans == -1 || ans > cost) {
                    ans = cost;
                }
            }
        }
    }
    cout << ans;
}