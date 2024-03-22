#include<bits/stdc++.h>
using namespace std;
int cnt, n, m, visited[100005];
vector <int> adj[100005];
void bfs(int s) {
	cnt ++;
	queue <int> q;
	q.push(s);
	visited[s] = 1;
	while(! q.empty()) {
		int u = q.front();
		q.pop();
		for(int i = 0; i < adj[u].size(); i ++) {
			int v = adj[u][i];
			if(! visited[v]) {
				visited[v] = 1;
				q.push(v);
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for(int i = 1; i <= m; i ++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 1; i <= n; i ++) if(! visited[i]) bfs(i);
	cout << cnt;
}
