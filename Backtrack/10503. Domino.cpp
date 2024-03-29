// https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1444
#include <bits/stdc++.h>
using namespace std;

int n, m, cnt, gg;
pair <int, int> a[23];
pair <int, int> b[23];
int check[23];

void backtrack(int pos) {
    if(pos == n + 1) {
        if(a[n].second == a[n + 1].first && gg == 0) {
            gg = 1;
            cnt ++;
        }
        return;
    }
    for(int i = 1; i <= m; i ++) {
        // place forward and check if this domino is used
        if(b[i].first == a[pos].second && check[i] == 0) {
            // mark as used
            check[i] = 1;
            a[pos + 1].first = b[i].first;
            a[pos + 1].second = b[i].second;
            backtrack(pos + 1);
            // mark as not used for another position
            check[i] = 0;
        }
        // place backward and check if this domino is used
        if(b[i].second == a[pos].second && check[i] == 0) {
            check[i] = 1;
            a[pos + 1].first = b[i].second;
            a[pos + 1].second = b[i].first;
            backtrack(pos + 1);
            check[i] = 0;
        }
    }
}

int main() {
    while(cin >> n) {
        if(n == 0) return 0;
        gg = 0;
        cnt = 0;
        cin >> m;
        cin >> a[0].first >> a[0].second;
        cin >> a[n + 1].first >> a[n + 1].second;
        for(int i = 1; i <= m; i ++) {
            cin >> b[i].first >> b[i].second;
        }
        backtrack(1);
        if(cnt == 0) cout << "NO" << endl;
        if(gg == 1) cout << "YES" << endl;
    }
}