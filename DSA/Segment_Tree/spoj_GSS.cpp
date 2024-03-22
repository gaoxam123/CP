#include <bits/stdc++.h>
using namespace std;
int n, m, a[100005];
struct node {
	int sum;
	int ans;
	int pre;
	int suf;
	node () {
	
	}
	node (int _sum, int _ans, int _pre, int _suf) {
		sum = _sum;
		ans = _ans;
		pre = _pre;
		suf = _suf;
	}
};
node add (node left, node right) {
	node res;
	res.sum = left.sum + right.sum;
	res.ans = max(max(left.ans, right.ans), left.suf + right.pre);
	res.pre = max(left.pre, left.sum + right.pre);
	res.suf = max(right.suf, right.sum + left.suf);
	return res;
}
node st[400005];
void build (int id, int l, int r) {
	if (l == r) {
		st[id] = node(a[l], a[l], a[l], a[l]);
		return;
	}
	int mid = (l + r) / 2;
	build (id * 2, l, mid);
	build (id * 2 + 1, mid + 1, r);
	st[id] = add(st[id * 2], st[id * 2 + 1]);
}
node get (int id, int l, int r, int u, int v) {
	if (l > v || r < u) return node(0, -1e9, -1e9, -1e9);
	if (l >= u && r <= v) return st[id];
	int mid = (l + r) / 2;
	return add(get(id * 2, l, mid, u, v), get (id * 2 + 1, mid + 1, r, u, v));
}
int main () {
	//ios_base::sync_with_stdio(0);
	//cin.tie(0); cout.tie(0);
	scanf ("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	build (1, 1, n);
	scanf ("%d", &m);
	while (m --) {
		int l, r;
		scanf ("%d %d", &l, &r);
		printf ("%d\n", get (1, 1, n, l, r).ans);
	}
	return 0;
}