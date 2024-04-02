// https://oj.uz/problem/view/IZhO14_blocks
#include <bits/stdc++.h>
using namespace std;

int N, K;
int a[100005], dp[105][100005], L[100005];

// int main() {
//     cin >> N >> K;
//     memset(dp, 1000000, sizeof(dp));
//     for(int i = 1; i <= N; i ++) {
//         cin >> a[i];
//     }
//     // THIS VERSION IS NOT OPTIMIZED, BUT WORKS PROPERLY
//     for(int i = 1; i <= K; i ++) {
//         for(int j = i; j <= N; j ++) {
//             if(i == 1) {
//                 if(j == 1) {
//                     dp[i][j] = a[j];
//                 }
//                 else {
//                     dp[i][j] = max(dp[i][j - 1], a[j]);
//                 }
//             }
//             else if(i == j) {
//                 dp[i][j] = dp[i - 1][j - 1] + a[j];
//             }
//             else {
//                 int mx = a[j];
//                 for(int k = j - 1; k >= i - 1; k --) {
//                     dp[i][j] = min(dp[i][j], dp[i - 1][k] + mx);
//                     mx = max(mx, a[k]);
//                 }
//             }       
//         }
//     }
//     cout << dp[K][N];
// }

// main idea: if a[j] is the same group as a[L[j]]
// same: then dp[i][j] = dp[i][L[j]], we don't care about dp[i - 1][k] with k < L[j]
// since a[j] < a[L[j]] then the cost of the last group doesn't change, so dp[i][L[j]] is optimal
// not same: we compare dp[i][L[j]] with dp[i - 1][k] for L[j] <= k < j, that is done by using a stack

int main() {
    cin >> N >> K;
    memset(dp, 1000000, sizeof(dp));
    for(int i = 1; i <= N; i ++) {
        cin >> a[i];
    }  
    dp[1][0] = 0;
    for(int i = 1; i <= N; i ++) {
        dp[1][i] = max(dp[1][i - 1], a[i]);
    }
    for(int i = 2; i <= K; i ++) {
        stack <pair <int, int> > st;
        for(int j = i; j <= N; j ++) {
            int minDP = dp[i - 1][j - 1];
            // st.top().second contains the closest k (L[j]), so that a[k] > a[j]
            // minDP is min dp[i - 1][k] for k in range(L[j], j)
            while(!st.empty() && a[st.top().second] <= a[j]) {
                minDP = min(minDP, st.top().first);
                st.pop();
            }
            dp[i][j] = min(minDP + a[j], dp[i][st.empty() ? 0 : st.top().second]);
            st.push(make_pair(minDP, j));
        }
    }
    cout << dp[K][N];
}