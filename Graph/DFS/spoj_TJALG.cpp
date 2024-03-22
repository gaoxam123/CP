#include <bits/stdc++.h>
using namespace std;

int n, m, low[100005], num[100005], ans, Time;
stack <int> st;
bool deleted[100005];
vector <int> adj[100005];

void dfs (int u){
	num[u] = low[u] = ++Time;
	st.push(u);
	for (int i = 0; i < adj[u].size(); i ++) {
		int v = adj[u][i];
		if(deleted[v]) continue;
		if(!num[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		}
		else low[u] = min(low[u], num[v]);
	}
	if (low[u] == num[u]) {
		ans ++;
		int v;
		do {
			v = st.top();
			st.pop();
			deleted[v] = true;
		}
		while (v != u);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < m; i ++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	for (int i = 1; i <= n; i ++) {
		if(!num[i]) dfs(i);
	}
	cout << ans;
	return 0;
}