// https://www.spoj.com/problems/NAKANJ/
#include <bits/stdc++.h>
using namespace std;

int a[10][10], visited[10][10], t, d[10][10];
vector <pair <int, int> > adj[10][10];
string s1, s2;
int moveX[] = {1, 2, -1, -2, 1, -2, 2, -1};
int moveY[] = {2, 1, -2, -1, -2, 1, -1, 2};

void bfs(int sx, int sy) {
    visited[sx][sy] = 1;
    queue <pair <int, int> > q;
    q.push(make_pair(sx, sy));
    while(!q.empty()) {
        int u = q.front().first;
        int v = q.front().second;
        q.pop();
        for(auto f: adj[u][v]) {
            int x = f.first, y = f.second;
            if(!visited[x][y]) {
                visited[x][y] = 1;
                d[x][y] = d[u][v] + 1;
                q.push(make_pair(x, y));
            }
        }
    }
}

int main() {
    for(int i = 1; i <= 8; i ++) {
        for(int j = 1; j <= 8; j ++) {
            for(int k = 0; k < 8; k ++) {
                int u = i + moveX[k];
                int v = j + moveY[k];
                if(u > 8 || v > 8 || u < 1 || v < 1) continue;
                adj[u][v].push_back(make_pair(i, j));
                adj[i][j].push_back(make_pair(u, v));
            }
        }
    }
    cin >> t;
    while(t --) {
        cin >> s1 >> s2;
        memset(d, 0, sizeof(d));
        memset(visited, 0, sizeof(visited));
        int sx, sy, tx, ty;
        sx = s1[1] - '1' + 1;
        sy = s1[0] - 'a' + 1;
        tx = s2[1] - '1' + 1;
        ty = s2[0] - 'a' + 1;
        bfs(sx, sy);
        cout << d[tx][ty] << endl;
    }
}