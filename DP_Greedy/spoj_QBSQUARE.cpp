// https://oj.vnoi.info/problem/qbsquare
#include<bits/stdc++.h>
using namespace std;
int n, m, a[1005][1005], dp[1005][1005], ans = 1;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	for(int j=1;j<=m;j++) dp[1][j]=1;
	for(int i=1;i<=n;i++) dp[i][1]=1;
	for(int i=2;i<=n;i++){
		for(int j=2;j<=m;j++){
			if(a[i][j] == a[i-1][j] && a[i][j] == a[i][j-1] && a[i][j] == a[i-1][j-1])
				dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
			else
				dp[i][j]=1;
			ans = max(ans, dp[i][j]);
		}
	}
	cout<<ans;
}

// #include <bits/stdc++.h>
// using namespace std;

// int m, n, a[1005][1005], sum[1005][1005], h1[1005], h2[1005];

// int main() {
//     cin >> m >> n;
//     for(int i = 1; i <= m; i ++) {
//         for(int j = 1; j <= n; j ++) {
//             cin >> a[i][j];
//         }
//     }
//     int ans = 0;
//     for(int k = 1; k <= m; k ++) {
//         for(int j = 1; j <= n; j ++) {
//             if(a[k][j] == 1) h1[j] ++;
//             else h1[j] = 0;
//         }
//         stack <int> st;
//         int l[n + 5], r[n + 5];
//         memset(l, 0, sizeof(l));
//         memset(r, 0, sizeof(r));

//         for(int j = 1; j <= n; j ++) {
//             while(!st.empty() && h1[st.top()] >= h1[j]) st.pop();
//             if(!st.empty()) l[j] = st.top() + 1;
//             else l[j] = 1;
//             st.push(j);
//         }
//         while(!st.empty()) st.pop();
//         for(int j = n; j >= 1; j --) {
//             while(!st.empty() && h1[st.top()] >= h1[j]) st.pop();
//             if(!st.empty()) r[j] = st.top() - 1;
//             else r[j] = n;
//             st.push(j);
//         }
//         for(int j = 1; j <= n; j ++) {
//             int side = min(r[j] - l[j] + 1, h1[j]);
//             ans = max(ans, side);
//         }
//     }

//     for(int k = 1; k <= m; k ++) {
//         for(int j = 1; j <= n; j ++) {
//             if(a[k][j] == 0) h2[j] ++;
//             else h2[j] = 0;
//         }
//         stack <int> st;
//         int l[n + 5], r[n + 5];
//         memset(l, 0, sizeof(l));
//         memset(r, 0, sizeof(r));

//         for(int j = 1; j <= n; j ++) {
//             while(!st.empty() && h2[st.top()] >= h2[j]) st.pop();
//             if(!st.empty()) l[j] = st.top() + 1;
//             else l[j] = 1;
//             st.push(j);
//         }
//         while(!st.empty()) st.pop();
//         for(int j = n; j >= 1; j --) {
//             while(!st.empty() && h2[st.top()] >= h2[j]) st.pop();
//             if(!st.empty()) r[j] = st.top() - 1;
//             else r[j] = n;
//             st.push(j);
//         }
//         for(int j = 1; j <= n; j ++) {
//             int side = min(r[j] - l[j] + 1, h2[j]);
//             ans = max(ans, side);
//         }
//     }
//     cout << ans;
// }
