// https://www.spoj.com/THPTCBT/problems/MTNTRAI/
#include <bits/stdc++.h>
using namespace std;

int n, m, chicken_count, fox_count;
char a[1005][1005];
bool visited[1005][1005];
int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void bfs(int sx, int sy) {
    visited[sx][sy] = true;
    queue <pair <int, int> > q;
    q.push(make_pair(sx, sy));
    int c_count = 0, f_count = 0;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(a[x][y] == 'c') c_count ++;
        if(a[x][y] == 'f') f_count ++;
        for(int i = 0; i < 4; i ++) {
            int u = x + moveX[i];
            int v = y + moveY[i];
            if(u > m || u < 1 || v > n || v < 1) continue;
            if(a[u][v] != '#' && !visited[u][v]) {
                visited[u][v] = true;
                q.push(make_pair(u, v));
            }
        }
    }
    if(c_count > f_count) fox_count -= f_count;
    else chicken_count -= c_count;
}

int main() {
    cin >> m >> n;
    for(int i = 1; i <= m; i ++) {
        for(int j = 1; j <= n; j ++) {
            cin >> a[i][j];
            if(a[i][j] == 'c') chicken_count ++;
            if(a[i][j] == 'f') fox_count ++;
        }
    }
    
    for(int i = 1; i <= m; i ++) {
        for(int j = 1; j <= n; j ++) {
            if(a[i][j] != '#' && !visited[i][j]) bfs(i, j);
        }
    }
    cout << fox_count << " " << chicken_count;
}