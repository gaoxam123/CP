#include <bits/stdc++.h>
using namespace std;
int n, a[100005], up[100005][23], q;
void build (int n, int a[]) {
    for (int i = 0; i < n; i ++) up[i][0] = i;
    for (int j = 1; 1 << j <= n; j ++) {
        for (int i = 0; i + (1 << j) - 1 < n; i ++) {
            if (a[up[i][j - 1]] < a[up[i + (1 << (j - 1))][j - 1]]) up[i][j] = up[i][j - 1];
            else up[i][j] = up[i + (1 << (j - 1))][j - 1];
        }
    }
} 
int get (int a[], int i, int j) {
    int k = __lg(j - i + 1);
    if (a[up[i][k]] <= a[up[j - (1 << k) + 1][k]])
        return up[i][k];
    else return up[j - (1 << k) + 1][k];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i ++) cin >> a[i];
    build (n, a);
    cin >> q;
    while (q --) {
        int l, r;
        cin >> l >> r;
        cout << get(a, l, r) << endl;
    }
    return 0;
}
