// https://oj.vnoi.info/problem/bedao_r06_exams
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, a[100005], product_2[100005], product_3[100005], sum[100005], mod = 1e9 + 7;

signed main() {
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        if(i == 2) product_2[i] = a[i] * a[i - 1];
        else {
            product_2[i] = product_2[i - 1] + a[i] * sum[i - 1];
            product_2[i] %= mod;
        }
        if(i == 3) product_3[i] = a[i] * a[i - 1] * a[i - 2];
        else {
            product_3[i] = product_3[i - 1] + product_2[i - 1] * a[i];
            product_3[i] %= mod;
        }
    }
    cout << product_3[n];
}