// https://cses.fi/problemset/task/1194/
#include <bits/stdc++.h>
using namespace std;

int n, m, visited[1005][1005], d[1005][1005];
char a[1005][1005];
queue <pair <int, int> > q;
int moveX[] = {1, -1, 0, 0};
int moveY[] = {0, 0, 1, -1};
vector <pair <int, int> > ans;
pair <int, int> par[1005][1005];
string directions;

int main() {
    cin >> n >> m;
    memset(d, -10000000, sizeof(d));
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> a[i][j];
            if(a[i][j] == 'A') {
                visited[i][j] = 1;
                par[i][j] = {-1, -1};
                d[i][j] = 0;
            }
            if(a[i][j] == 'M') {
                visited[i][j] = 1;
                q.push({i, j});
            }
        }
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(a[i][j] == 'A') {
                q.push({i, j});
                break;
            }
        }
    }
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i ++) {
            int u = x + moveX[i];
            int v = y + moveY[i];
            if(u < 1 || v < 1 || u > n || v > m) continue;
            if(!visited[u][v] && a[u][v] != '#') {
                visited[u][v] = 1;
                par[u][v] = {x, y};
                d[u][v] = d[x][y] + 1;
                q.push({u, v});
            }
        }
    }
    int cnt = 0, escape_x = 0, escape_y = 0;
    for(int i = 1; i <= n; i ++) {
        if(d[i][1] >= 0) { 
            cnt ++;
            escape_x = i, escape_y = 1;
            break;
        }
        if(d[i][m] >= 0) { 
            cnt ++;
            escape_x = i, escape_y = m;
            break;
        }
    }
    if(cnt == 0) {
        for(int i = 1; i <= m; i ++) {
            if(d[1][i] >= 0) { 
                cnt ++;
                escape_x = 1, escape_y = i;
                break;
            }
            if(d[n][i] >= 0) { 
                cnt ++;
                escape_x = n, escape_y = i;
                break;
            }
        }
    }
    if(cnt == 0) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl << d[escape_x][escape_y] << endl;
    for(pair <int, int> v = {escape_x, escape_y}; v.first != -1; v = par[v.first][v.second]) {
        ans.push_back(v);
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