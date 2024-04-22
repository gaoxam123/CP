#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, k, dp[300005], pos[300005], maxx[300005], maxy[300005];

struct Lotus {
	int x, y, w, id;
	bool operator < (const Lotus &o) const {
		if (x < o.x) return true;
		if (x == o.x && y < o.y) return true;
		return false;
	}
};

Lotus a[300005];

void update(int i) {
    maxx[a[i].x] = max(maxx[a[i].x], dp[i]);
    maxy[a[i].y] = max(maxy[a[i].y], dp[i]);
}

signed main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i].x >> a[i].y >> a[i].w;
        a[i].id = i;
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i ++) {
        pos[a[i].id] = i;
    }
    dp[pos[1]] = a[pos[1]].w;
    update(pos[1]);
    for(int i = pos[1] + 1; i <= n; i ++) {
        if(maxx[a[i].x] >= k) {
            dp[i] = max(dp[i], maxx[a[i].x] - k + a[i].w);
        }
        if(maxy[a[i].y] >= k) {
            dp[i] = max(dp[i], maxy[a[i].y] - k + a[i].w);
        }
        update(i);
    }
    cout << dp[pos[n]];
}