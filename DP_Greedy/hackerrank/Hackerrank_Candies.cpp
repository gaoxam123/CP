// https://www.hackerrank.com/challenges/candies/problem
#include <bits/stdc++.h>
using namespace std;

int n, a[100005], b[100005], c[100005], ans;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        if(i == 1) b[i] = 1;
        else {
            if(a[i] > a[i - 1]) b[i] = b[i - 1] + 1;
            else b[i] = 1;
        }
    }
    c[n] = 1;
    for(int i = n - 1; i >= 1; i --) {
        if(a[i] > a[i + 1]) c[i] = c[i + 1] + 1;
        else c[i] = 1;
    }
    for(int i = 1; i <= n; i ++) {
        ans += max(b[i], c[i]);
    }
}