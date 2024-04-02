// https://oj.vnoi.info/problem/c11cave
#include <bits/stdc++.h>
using namespace std;

int n, h, ans, cnt;
int a[200005];
vector <int> down;
vector <int> up;
int numObstacles[500005];

int main() {
    cin >> n >> h;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        if(i % 2 == 1) down.push_back(a[i]);
        else up.push_back(a[i]);
    }
    sort(down.begin(), down.end());
    sort(up.begin(), up.end());
    for(int i = 1; i <= h; i ++) {
        auto pos1 = lower_bound(down.begin(), down.end(), i);
        int p1 = pos1 - down.begin();
        numObstacles[i] = down.size() - p1;

        int reverse_height = h - i + 1;
        auto pos2 = lower_bound(up.begin(), up.end(), reverse_height);
        int p2 = pos2 - up.begin();
        numObstacles[i] += (up.size() - p2);
    }
    sort(numObstacles + 1, numObstacles + h + 1);
    ans = numObstacles[1];
    for(int i = 1; i <= h; i ++) {
        if(numObstacles[i] == ans) cnt ++;
        else break;
    }
    cout << ans << " " << cnt;
}