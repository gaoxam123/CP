#include <bits/stdc++.h>
using namespace std;

int n, a[100005], st[100005];

void build(int id, int l, int r) {
    if(l > r) return;
    if(l == r) {
        st[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    st[id] = max(st[2 * id], st[2 * id + 1]);
}

void update(int id, int l, int r, int pos, int val) {
    if(pos < l || pos > r) return;
    if(l == r) {
        st[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(2 * id, l, mid, pos, val);
    update(2 * id + 1, mid + 1, r, pos, val);
    st[id] = max(st[2 * id], st[2 * id + 1]);
}

int get(int id, int l, int r, int u, int v) {
    if(l > v || r < u) return 0;
    if(l >= u && r <= v) return st[id];

    int mid = (l + 2) / 2;
    int get1 = get(2 * id, l, mid, u, v);
    int get2 = get(2 * id + 1, mid + 1, r, u, v);
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
        int l, r, x, pos, val;
        cin >> x;
        if(x == 1) {
            cin >> pos >> val;
            update(1, 1, n, pos, val);
        } 
        else {
            cin >> l >> r;
            cout << get(1, 1, n, l, r) << endl;
        }
    }
    return 0;
}