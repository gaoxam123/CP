// https://oj.vnoi.info/problem/xucxac
#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[55][55], d[55][55][10][10], s, t, u, v;

struct data1 {
    int i, j, bottom, c, front, up, right;
    bool operator < (const data1 &o) const {
        return c > o.c;
    }
};

priority_queue <data1> pq;

void front(data1 x) {
    int i = x.i, j = x.j, p = i + 1, q = j;
    int front = x.up, up = 7 - x.front, right = x.right, bottom = 7 - up;
    if(p <= n && d[p][q][bottom][front] > d[i][j][x.bottom][x.front] + a[p][q] * bottom) {
        d[p][q][bottom][front] = d[i][j][x.bottom][x.front] + a[p][q] * bottom;
        pq.push({p, q, bottom, d[p][q][bottom][front], front, up, right});
    }
}

void back(data1 x) {
    int i = x.i, j = x.j, p = i - 1, q = j;
    int front = 7 - x.up, up = x.front, right = x.right, bottom = 7 - up;
    if(p > 0 && d[p][q][bottom][front] > d[i][j][x.bottom][x.front] + a[p][q] * bottom) {
        d[p][q][bottom][front] = d[i][j][x.bottom][x.front] + a[p][q] * bottom;
        pq.push({p, q, bottom, d[p][q][bottom][front], front, up, right});
    }
}

void left(data1 x) {
    int i = x.i, j = x.j, p = i, q = j - 1;
    int front = x.front, up = x.right, right = 7 - x.up, bottom = 7 - up;
    if(q > 0 && d[p][q][bottom][front] > d[i][j][x.bottom][x.front] + a[p][q] * bottom) {
        d[p][q][bottom][front] = d[i][j][x.bottom][x.front] + a[p][q] * bottom;
        pq.push({p, q, bottom, d[p][q][bottom][front], front, up, right});
    }
}

void right(data1 x) {
    int i = x.i, j = x.j, p = i, q = j + 1;
    int front = x.front, up = 7 - x.right, right = x.up, bottom = 7 - up;
    if(q <= m && d[p][q][bottom][front] > d[i][j][x.bottom][x.front] + a[p][q] * bottom) {
        d[p][q][bottom][front] = d[i][j][x.bottom][x.front] + a[p][q] * bottom;
        pq.push({p, q, bottom, d[p][q][bottom][front], front, up, right});
    }
}

void dijkstra() {
    memset(d, 0x3f, sizeof(d));
    d[s][t][5][1] = 5 * a[s][t];
    pq.push({s, t, 5, d[s][t][5][1], 1, 2, 3});
    while(!pq.empty()) {
        auto x = pq.top();
        pq.pop();
        if(x.c > d[x.i][x.j][x.bottom][x.front]) continue;
        front(x);
        back(x);
        left(x);
        right(x);
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }
    }
    cin >> s >> t >> u >> v;
    int ans = 1e9;
    dijkstra();
    for(int i = 1; i <= 6; i ++) {
        for(int j = 1; j <= 6; j ++) {
            if(j == i || j == 7 - i) continue;
            ans = min(ans, d[u][v][i][j]);
        }
    }
    cout << ans;
}