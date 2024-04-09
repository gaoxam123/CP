// https://oj.vnoi.info/problem/kandp
#include <bits/stdc++.h>
using namespace std;

int mx, my, tx, ty, turn, ans;
int root = 3000, inq[6000][6000], d[6000][6000];
int moveX[] = {1, 2, -1, -2, 1, -2, 2, -1};
int moveY[] = {2, 1, -2, -1, -2, 1, -1, 2};

int main() {
    cin >> mx >> my >> tx >> ty >> turn;
    if(turn) {
        turn = 0;
        tx --;
    }
    if((mx - tx + my - ty) % 2 == 0) {
        cout << "NO";
        return 0;
    }
    queue <pair <int, int> > q;
    q.push(make_pair(mx, my));
    d[mx + root][my + root] = 1;
    inq[mx + root][my + root] = 1;
    int dx = abs(mx - tx) + 30;
    int dy = abs(my - ty) + 30;

    while(true) {
        if(turn) {
            tx --;
            for(int i = 0; i < 8; i ++) {
                if(inq[tx + moveX[i] + root][ty + moveY[i] + root]) {
                    cout << "YES" << endl << ans + 1;
                    return 0;
                }
            }
        }
        else {
            ans ++;
            int sz = q.size();
            while(sz --) {
                pair <int, int> f = q.front();
                q.pop();
                inq[f.first + root][f.second + root] = 1;
                for(int i = 0; i < 8; i ++) {
                    int u = f.first + moveX[i];
                    int v = f.second + moveY[i];
                    if(d[u + root][v + root]) continue;
                    if(abs(u - tx) > dx || abs(v - ty) > dy) continue;
                    if(v < -1002 || v > 1002) continue;
                    q.push(make_pair(u, v));
                    d[u + root][v + root] = 1;
                    inq[u + root][v + root] = 1;
                }
            }
        }
        turn = 1 - turn;
    }
}