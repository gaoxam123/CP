#include <bits/stdc++.h>
using namespace std;
int n, m, up[100005], sz[100005], ans = -1e9;
vector <pair <int, pair <int, int> > > edge;
void make_set (int v) {
	up[v] = v;
	sz[v] = 1;
}
int fine (int v) {
	if (v == up[v]) return v;
	up[v] = fine (up[v]);
	return up[v];
}
void onion (int u, int v) {
	u = fine (u);
	v = fine (v);
	if (u != v) {
		if (sz[u] < sz[v]) swap (u, v);
		up[v] = u;
		sz[u] += sz[v];
	}
}
bool same_set (int u, int v) {
	return fine (u) == fine (v);
}
int main () {
	cin >> n >> m;
	for (int i = 1; i <= m; i ++) {
		int u, v, w;
		cin >> u >> v >> w;
		edge.push_back (make_pair (w, make_pair (u, v)));
	}
	for (int i = 1; i <= n; i ++) make_set(i);
	sort (edge.begin(), edge.end());
	for (int i = 0; i < m; i ++) {
		pair <int, pair <int, int> > gg = edge[i];
		if (! same_set (gg.second.first, gg.second.second)) {
			ans = max(ans, gg.first);
			onion (gg.second.first, gg.second.second);
		}
	}
	cout << ans;
} 