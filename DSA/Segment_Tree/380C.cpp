#include<bits/stdc++.h>
using namespace std;
string s;
int n, x, y;
struct Node {
    int ans;
    int open;
    int close;
    Node() {
        ans = open = close = 0;
    }
    Node(int _ans, int _open, int _close) {
        ans = _ans;
        open = _open;
        close = _close;
    }
};
Node operator+ (const Node& left, const Node& right) {
    Node res;
    int tmp = min(left.open, right.close);
    res.ans = left.ans + right.ans + tmp * 2;
    res.open = left.open + right.open - tmp;
    res.close = left.close + right.close - tmp;
    return res;
}
Node a[400005];
void build(int id, int l, int r) {
    if (l == r) {
        if (s[l] == '(') a[id] = Node(0, 1, 0);
        else a[id] = Node(0, 0, 1);
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    a[id] = a[id * 2] + a[id * 2 + 1];
}
Node query(int id, int l, int r, int u, int v) {
    if (v < l || u > r) {
        return Node(0, 0, 0);
    }
    if (u <= l && r <= v) {
        return a[id];
    }
    int mid = (l + r) / 2;
    return query(id * 2, l, mid, u, v) + query(id * 2 + 1, mid + 1, r, u, v);
}
int main() {
    cin >> s;
    s = " " + s;
    cin >> n;
    build (1, 1, s.size() - 1);
    while (n--) {
        cin >> x >> y;
        cout << query(1, 1, s.size() - 1, x, y).ans << endl;
    }
}
