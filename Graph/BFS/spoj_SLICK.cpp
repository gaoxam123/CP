// https://www.spoj.com/problems/UCV2013H/
#include <bits/stdc++.h>
using namespace std;

int n, m;
bool a[305][305], visited[305][305];
vector <int> slicks;
int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void reset() {
    slicks.clear();
    for (int i = 1; i <= n; ++i)
        fill_n(visited[i], m + 1, false);
}

int bfs(int sx, int sy) {
    int sizeSlick = 1;
    queue <pair <int, int> > q;
    q.push(make_pair(sx, sy));
    visited[sx][sy] = true;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i ++) {
            int u = x + moveX[i];
            int v = y + moveY[i];

            if(u > n || u < 1) continue;
            if(v > m || v < 1) continue;

            if(a[u][v] && !visited[u][v]) {
                sizeSlick ++;
                visited[u][v] = true;
                q.push(make_pair(u, v));
            }
        }
    }
    return sizeSlick;
}

int main() {
    while(cin >> n >> m) {
        if(!n && !m) return 0;
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= m; j ++) {
                cin >> a[i][j];
            }
        }
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= m; j ++) {
                if(a[i][j] && !visited[i][j]) {
                    slicks.push_back(bfs(i, j));
                }
            }
        }
        cout << slicks.size() << endl;
        sort(slicks.begin(), slicks.end());
        slicks.push_back(1e9);
        int number = 0, pre = slicks[0];
        for(auto v: slicks) {
            if(v != pre) {
                cout << pre << " " << number << endl;
                pre = v;
                number = 1;
            }
            else number ++;
        }
        reset();
    }
}