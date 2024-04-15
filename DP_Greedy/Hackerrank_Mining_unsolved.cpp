#include <bits/stdc++.h>
using namespace std;

int n, k, d[5005], w[5005], dp[5005][5005], cost[5005][5005];

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) {
        cin >> d[i] >> w[i];
    }
    // cost of putting j first mines at pos i
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= i; j ++) {
            cost[i][j] = cost[i][j - 1] + (d[i] - d[j]) * w[j]; 
        }
        for(int j = i + 1; j <= n; j ++) {
            cost[i][j] = cost[i][j - 1] + (d[j] - d[i]) * w[j];
        }
    }
    
}