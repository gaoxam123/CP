#include<bits/stdc++.h>
using namespace std;
int cnt, n, m, a[1005][1005], ans, col[1005][1005];
int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			cin >> a[i][j];
		}
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m;j ++) {
			col[i][j] = col[i - 1][j] + a[i][j];
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = i ; j <= n; j ++) {
			cnt = 0;
			for(int k = 1; k <= m; k ++) {
				if(col[j][k] - col[i - 1][k] == j - i + 1) {
					cnt ++;
					ans = max(ans, cnt * (j - i + 1));
				}
				else cnt = 0;
			}
		}
	}
	cout << ans;
}
//KAGAIN

// #include <bits/stdc++.h>
// using namespace std;

// int n, m, a[1005][1005], ans = -1e9;
// int h[1005];

// int main() {
//     cin >> n >> m;
//     for(int i = 1; i <= n; i ++) {
//         for(int j = 1; j <= m; j ++) {
//             cin >> a[i][j];
//         }
//     }
//     for(int k = 1; k <= n; k ++) {
//         for(int j = 1; j <= m; j ++) {
//             if(a[k][j] == 1) h[j] ++;
//             else h[j] = 0;
//         }
//         int l[m + 1], r[m + 1];
//         memset(l, 0, sizeof(l));
//         memset(r, 0, sizeof(r));
//         stack <int> st;
//         for(int i = 1; i <= m; i ++) {
//             while(!st.empty() && h[st.top()] >= h[i]) st.pop();
//             if(!st.empty()) l[i] = st.top() + 1;
//             else l[i] = 1;
//             st.push(i);
//         }
//         while(!st.empty()) st.pop();
//         for(int i = m; i >= 1; i --) {
//             while(!st.empty() && h[st.top()] >= h[i]) st.pop();
//             if(!st.empty()) r[i] = st.top() - 1;
//             else r[i] = m;
//             st.push(i);
//         }
//         for(int i = 1; i <= m; i ++) {
//             int area = (r[i] - l[i] + 1) * h[i];
//             ans = max(ans, area);
//         }
//     }
//     cout << ans;
// }