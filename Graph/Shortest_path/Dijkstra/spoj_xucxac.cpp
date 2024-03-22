// https://vnspoj.github.io/problems/XUCXAC.html
#include <bits/stdc++.h>
using namespace std;

int n, m, x1, y1, x2, y2, inf = 1e9;
int a[105][105], dp[105][105][10][10], s, t;

struct data1 {
    int i, j, duoi, c, truoc, tren, phai;
    bool operator <(const data1 &o) const {
        return c < o.c;
    }
};

priority_queue <data1> pq;

void truoc(data1 x) {
    
}