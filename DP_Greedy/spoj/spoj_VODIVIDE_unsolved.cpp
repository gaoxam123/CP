#include<bits/stdc++.h>
using namespace std;
int n, dp[5005][5005];
struct x {
	int a; int b; int id;
};
bool cmp (x &z, x &t) {
	return z.a < t.a;
}
x gg[5005];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> gg[i].a;
	}
	for (int i = 1; i <= n; i ++) {
		cin >> gg[i].b;
		gg[i].id = i;
	}
	sort (gg + 1, gg + n + 1, cmp);
	dp[1][1] = gg[1].b;
	for (int i = 2; i <= n; i ++) {
		dp[i][0] = dp[i - 1][1];
		if (i <= n / 2) dp[i][i] = dp[i-1][i-1] + gg[i].b;
		for (int j = 1; j < i; j ++) dp[i][j] = max (dp[i - 1][j + 1], dp[i - 1][j - 1] + gg[i].b);
	} 
	cout << dp[n][0];
}
/*#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct pack { int a, b, index; };
bool cmp_a(const pack &a, const pack &b) {
    return a.a < b.a;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<pack> x(n);
    for (int i=0; i<n; i++) x[i].index = i + 1;
    for (int i=0; i<n; i++) cin >> x[i].a;
    for (int i=0; i<n; i++) cin >> x[i].b;

    sort(x.begin(), x.end(), cmp_a);
    priority_queue< pair<int, int> > heap;
    vector<bool> take(n, false);
    long long res = 0;
    for (int i=0; i<n; i++) {
        heap.push(make_pair(x[i].b, i));
        if (i%2 == 0) {
            pair<int, int> t = heap.top();
            heap.pop();
            res += (long long)t.first;
            take[t.second] = true;
        }
    }

    cout << res << '\n';
    vector<int> stack;
    for (int i=0; i<n; i++) {
        if (take[i]) stack.push_back(x[i].index);
        else {
            cout << x[i].index << ' ' << stack.back() << '\n';
            stack.pop_back();
        }
    }
    return 0;
}*/
