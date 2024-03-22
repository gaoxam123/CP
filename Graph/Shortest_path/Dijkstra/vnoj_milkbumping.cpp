#include <bits/stdc++.h>
using namespace std;

struct data1 {
    int node;
    int sum_weight;
    int min_size;
    float value;

    data1 (int _node, int _sum_weight, int _min_size, float _value) {
        node = _node;
        sum_weight = _sum_weight;
        min_size = _min_size;
        value = _value;
    }

    bool operator <(const data1 &other) const {
        return other.value < value;
    }
};

struct data2 {
    int node;
    int weight;
    int size;
    data2(int _node, int _weight, int _size) {
        node = _node;
        weight = _weight;
        size = _size;
    }
};

int n, m;
vector <data2> adj[1005];
priority_queue <data1> pq;
float d[1005];

int main() {
    cin >> n >> m;

    for(int i = 1; i <= m; i ++) {
        int u, v, w, s;
        cin >> u >> v >> w >> s;
        adj[u].push_back(data2(v, w, s));
        adj[v].push_back(data2(u, w, s));
    }

    for(int i = 1; i <= n; i ++) d[i] = -1e9;
    d[1] = 0;
    pq.push(data1(1, 0, 1e9, 0));
    while(!pq.empty()) {
        data1 u = pq.top();
        pq.pop();
        if(u.value > d[u.node]) continue;
        for(auto v: adj[u.node]) {
            if(d[v.node] < (double)min(u.min_size, v.size) / (u.sum_weight + v.weight)) {
                d[v.node] = (double)min(u.min_size, v.size) / (u.sum_weight + v.weight);
                pq.push(data1(v.node, u.sum_weight + v.weight, min(u.min_size, v.size), d[v.node]));
            }
        } 
    }
    cout << (int)(d[n] * 1e6);
}