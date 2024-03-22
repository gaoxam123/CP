#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, q, a[100005], st[400005], lazy[400005];

void build(int id, int l, int r) {
    if (l == r) {
        st[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    st[id] = max(st[2 * id], st[2 * id + 1]);
}

void fix(int id, int l, int r) {
    if (!lazy[id]) return;
    st[id] += lazy[id];
    if (l != r){
        lazy[2 * id] += lazy[id];
        lazy[2 * id + 1] += lazy[id];
    }
    
    lazy[id] = 0;
}

void update(int id, int l, int r, int u, int v, int val) {
    fix(id, l, r);
    if (l >  v || r <  u) return;
    if (l >= u && r <= v) {
        lazy[id] += val;
        fix(id, l, r);
        return;
    }
    int mid = (l + r) / 2;
    update(2 * id, l, mid, u, v, val);
    update(2 * id + 1, mid + 1, r, u, v, val);
    st[id] = max(st[2 * id], st[2 * id + 1]);
}

int get(int id, int l, int r, int u, int v) {
    fix(id, l, r);
    if (l >  v || r <  u) return -1e9;
    if (l >= u && r <= v) return st[id];

    int mid  = (l + r) / 2;
    int get1 = get(2 * id, l, mid, u, v);
    int get2 = get(2 * id + 1, mid + 1, r, u, v);
    return max(get1, get2);
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    
    cin >> q;
    while (q--){
        int gg, l, r, val;
        cin >> gg >> l >> r;
        if (gg == 1) {
            cin >> val;
            update(1, 1, n, l, r, val);
        }
        else cout << get(1, 1, n, l, r) << endl;
    }
	return 0;
}
