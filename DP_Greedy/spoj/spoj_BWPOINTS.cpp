#include<bits/stdc++.h>
using namespace std;
int n, cnt, ans, maulon;
pair <int, int> a[200005];
bool cmp(pair<int, int> gg, pair<int, int> ff){
	return gg.first<ff.first;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[++cnt].first;
		a[i].second = 0;
	}
	for(int i=n+1;i<=2*n;i++){
		cin>>a[++cnt].first;
		a[i].second = 1;
	}
	sort(a+1, a+cnt+1, cmp);
	maulon = a[1].second;
	for(int i=2;i<=cnt;i++){
		if(a[i].second + maulon==1) {
			ans++;
			maulon = -1;
		}
		else maulon = a[i].second;
	}
	cout<<ans;
}

// #include <bits/stdc++.h>
// using namespace std;

// int n;
// pair <int, int> a[200005];
// map <int, bool> check;

// bool compare(pair <int, int> x, pair <int, int> y) {
//     return x.first < y.first;
// }

// int main() {
//     cin >> n;
//     for(int i = 1; i <= 2 * n; i ++) {
//         cin >> a[i].first;
//         if(i <= n) a[i].second = 0;
//         else a[i].second = 1;
//     }
//     sort(a + 1, a + 2 * n + 1, compare);
//     int ans = 0;
//     int currentColor = a[1].second;
//     for(int i = 1; i < 2 * n; i ++) {
//         if(!check[i] && !check[i + 1]) {
//             if(a[i].second != a[i + 1].second) {
//                 ans ++;
//                 check[i] = check[i + 1] = true;
//             }
//         }
//     } 
//     cout << ans;
// }
