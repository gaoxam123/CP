#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector <pair <int, int> > adj[100005];
vector <pair <int, int> > co;

void dijkstra(int s, vector <int> &d) {
	priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > pq;
	pq.push(make_pair(0, s));
	d[s] = 0;
	while(!pq.empty()) {
		pair <int, int> u = pq.top();
		pq.pop();
		if(u.first > d[u.second]) continue;
		
		for(int i = 0; i < adj[u.second].size(); i ++) {
			pair <int, int> v = adj[u.second][i];
			if(d[v.first] > d[u.second] + v.second) {
				d[v.first] = d[u.second] + v.second;
				pq.push(make_pair(d[v.first], v.first));
			}
		}
	}
}

int main() {
	
	cin >> n >> m >> k;
	co.resize(k + 10);
	
	for(int i = 1; i <= m; i ++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}
	
	for(int i = 1; i <= k; i ++) {
		int a, b;
		cin >> a >> b;
		co[i] = make_pair(a, b);
	}
	vector <int> d1, d2;
	d1.resize(n + 2);
	d2.resize(n + 3);
	for(int i = 1; i <= n + 1; i ++) d1[i] = d2[i] = 1e9;
	dijkstra(n, d1);
	
	for(int i = 1; i <= k; i ++) {
		adj[n + 1].push_back(make_pair(co[i].first, d1[co[i].first] - co[i].second));
	} 
	dijkstra(n + 1, d2);
	
	for(int i = 1; i < n; i ++) {
		if(d2[i] > d1[i]) cout << "0" << endl;
		else cout << "1" << endl;
	}
	return 0;
}