#include <bits/stdc++.h>
using namespace std;

int n, a[100005], st[400005], lazy[400005];

void build(int id, int l, int r) {
    if(l > r) return;
    if(l == r) {
        st[id] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}

void fix(int id, int l, int r) {
    if(!lazy[id]) return;
    st[id] += lazy[id];

    if(l != r) {
        lazy[id * 2] += lazy[id];
        lazy[id * 2 + 1] += lazy[id];
    }
    lazy[id] = 0;
}

void update(int id, int l, int r, int u, int v, int val) {
    fix(id, l, r);
    if(l > v || r < u) return;
    if(l >= u && r <= v) {
        lazy[id] += val;
        fix(id, l, r);
        return;
    }
    int mid = l + r >> 1;
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v) {
    fix(id, l, r);
    if(l > v || r < u) return -1e9;
    if(l >= u && r <= v) return st[id];

    int mid = l + r >> 1;
    int get1 = get(id * 2, l, mid, u, v);
    int get2 = get(id * 2 + 1, mid + 1, r, u, v);
    return max(get1, get2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];

    build(1, 1, n);

    int q;
    cin >> q;
    while(q --) {
        int l, r, x, u, v, val;
        cin >> x;
        if(x == 1) {
            cin >> u >> v >> val;
            update(1, 1, n, u, v, val);
        } 
        else {
            cin >> l >> r;
            cout << get(1, 1, n, l, r) << endl;
        }
    }
    return 0;
}   