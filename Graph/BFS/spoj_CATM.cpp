// https://www.spoj.com/problems/CATM/
#include <bits/stdc++.h>
using namespace std;

int n, m, k;

int main() {
    cin >> n >> m >> k;
    while(k --) {
        int mx, my, c1x, c1y, c2x, c2y;
        cin >> mx >> my >> c1x >> c1y >> c2x >> c2y;
        int escape_up = mx - 1, escape_down = n - mx, escape_left = my - 1, escape_right = m - my;
        int c1_up = abs(c1y - my) + c1x - 1, c1_down = abs(c1y - my) + n - c1x, c1_left = abs(c1x - mx) + c1y - 1, c1_right = abs(c1x - mx) + m - c1y;
        int c2_up = abs(c2y - my) + c2x - 1, c2_down = abs(c2y - my) + n - c2x, c2_left = abs(c2x - mx) + c2y - 1, c2_right = abs(c2x - mx) + m - c2y;
        if((escape_up >= c1_up || escape_up >= c2_up) && (escape_down >= c1_down || escape_down >= c2_down) && (escape_left >= c1_left || escape_left >= c2_left) && (escape_right >= c1_right || escape_right >= c2_right)) {
            cout << "NO" << endl;
        }
        else cout << "YES" << endl;
        // if(escape_right < c1_right) cout << "YES" << endl;
        // else cout << "NO" << endl;
    }
}