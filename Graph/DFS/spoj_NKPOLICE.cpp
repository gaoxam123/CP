#include <bits/stdc++.h>
using namespace std;

int n, m, low[100005], num[100005], tail[100005], joint[100005], Time, h[100005], up[100005][23], q;
vector <int> adj[100005];

void init(){
	up[1][0] = 1;
	for (int j = 1; j <= 20; j ++) {
		for (int i = 1; i <= n; i ++) {
			up[i][j] = up[up[i][j - 1]][j - 1];
		}
	}
}

int find (int u, int p){
	for (int i = 20; i >= 0; i --) {
		if (h[up[u][i]] > h[p]) u = up[u][i];
	}
	return u;
}

void dfs(int u, int pre) {
	int child = 0;
	num[u] = low[u] = ++Time;
	for(int i = 0; i < adj[u].size(); i ++){
		int v = adj[u][i];
		if (v == pre) continue;
		if(!num[v]) {
			child ++;
            up[v][0] = u;
			h[v] = h[u] + 1;
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if (u == pre) {
                if(child > 1) joint[u] = 1;
            }
			else if(low[v] >= num[u]) joint[u] = 1;
		}
		else low[u] = min(low[u], num[v]);
	}
	tail[u] = Time;
}

bool inSubtree(int u, int root){
	return num[root] <= num[u] && num[u] <= tail[root];
}

bool solve1(int a, int b, int g1, int g2){
	if(num[g1] > num[g2]) swap(g1, g2);
	if(low[g2] != num[g2]) return true;
	if(inSubtree(a, g2) && !inSubtree(b, g2)) return false;
	if(inSubtree(b, g2) && !inSubtree(a, g2)) return false;
	return true;
}

bool solve2(int a, int b, int c){
	if(!joint[c]) return true;
	int pa = 0, pb = 0;
	if(inSubtree(a, c)) pa = find(a, c);
	if(inSubtree(b, c)) pb = find(b, c);

	if(!pa && !pb) return true;
	if(pa == pb) return true;
	if(!pa && low[pb] < num[c]) return true;
	if(!pb && low[pa] < num[c]) return true;
	if(pa && pb && low[pa] < num[c] && low[pb] < num[c]) return true;
    
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i ++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	h[1] = 1;
	dfs(1, 1);
	init();
	cin >> q;
	while (q--) {
		int x, a, b, c, g1, g2;
		cin >> x >> a >> b;
		if (x == 1) {
			cin >> g1 >> g2;
			if(solve1(a, b, g1, g2)) cout << "yes" << endl;
			else cout << "no" << endl;
		}
		else {
			cin >> c;
			if(solve2(a, b, c)) cout << "yes" << endl;
			else cout << "no" << endl;
		}
	}
	return 0;
}