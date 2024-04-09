// https://cses.fi/problemset/task/1193
#include <bits/stdc++.h>
using namespace std;

int n, m, k, visited[1005][1005], d[1005][1005];
pair <int, int> par[1005][1005];
int moveX[] = {1, -1, 0, 0};
int moveY[] = {0, 0, 1, -1};
string directions;
char a[1005][1005];
vector <pair <int, int> > ans;

void bfs(int sx, int sy) {
    queue <pair <int, int> > q;
    q.push({sx, sy});
    visited[sx][sy] = 1;
    par[sx][sy] = {-1, -1};
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i ++) {
            int u = x + moveX[i];
            int v = y + moveY[i];
            if(u > n || v > m || u < 1 || v < 1) continue;
            if(!visited[u][v] && a[u][v] != '#') {
                d[u][v] = d[x][y] + 1;
                par[u][v] = {x, y};
                visited[u][v] = true;
                q.push({u, v});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    int sx, sy, tx, ty;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> a[i][j];
            if(a[i][j] == 'A') {
                sx = i;
                sy = j;
            }
            if(a[i][j] == 'B') {
                tx = i;
                ty = j;
            }
        }
    }
    bfs(sx, sy);
    if(d[tx][ty] == 0) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl << d[tx][ty] << endl;
    for(pair <int, int> v = {tx, ty}; v.first != -1; v = par[v.first][v.second]) {
        ans.push_back({v.first, v.second});
    }
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < ans.size() - 1; i ++) {
        auto u = ans[i];
        auto v = ans[i + 1];
        if(u.first == v.first) {
            if(u.second == v.second + 1) directions += "L";
            else directions += "R";
        }
        else {
            if(u.first == v.first - 1) directions += "D";
            else directions += "U";
        }
    }
    cout << directions;
}