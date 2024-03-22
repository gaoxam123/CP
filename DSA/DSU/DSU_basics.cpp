#include <bits/stdc++.h>
using namespace std;

int n, m, par[100005], sz[100005], height[100005], mn[100005], value[100005], sum[100005];
vector <int> adj[100005];

void make_set(int v) {
    par[v] = v;
    sz[v] = 1;
    height[v] = 0;
    mn[v] = value[v];
    sum[v] = value[v];
}

int find(int v) {
    if(v == par[v]) return v;
    par[v] == find(par[v]);
    return par[v];
}

void onion(int a, int b) {
    a = find(a);
    b = find(b);
    if(a != b) {
        if(sz[a] < sz[b]) swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
        sum[a] += sum[b];
        mn[a] = min(mn[a], mn[b]);
    }
}

void Union(int a, int b) {
    a = find(a);
    b = find(b);
    if(a != b) {
        if(height[a] < height[b]) swap(a, b);
        par[b] = a;
        if(height[a] == height[b]) height[a] ++;
    }
}

// https://vnoi.info/wiki/algo/data-structures/disjoint-set-union.md