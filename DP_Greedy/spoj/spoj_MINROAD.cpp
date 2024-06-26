/*int Search_a(int l, int r, int a) {
	int ans = -1;
	while (l <= r) {
		int mid = (l+r)/2;
		if (fa[mid] <= a) {
			ans = mid;
			l = mid+1;
		} else
			r = mid-1;
	}
	return ans;
}
int Search_b(int l, int r, int b) {
	int ans = -1;
	while (l <= r) {
		int mid = (l+r)/2;
		if (fb[mid] <= b) {
			ans = mid;
			l = mid+1;
		} else
			r = mid-1;
	}
	return ans;
}
int main() {
	scanf("%d%d%d", &n,&A,&B);
	for (int i=1; i<=n; i++)
		scanf("%lld %d", &a[i].d,&a[i].t);
	sort(a+1,a+n+1,cmp);
	for (int i=1; i<=n; i++) {
		fd[i] = a[i].d;
		fa[i] = fa[i-1] + (a[i].t == 1);
		fb[i] = fb[i-1] + (a[i].t == 2);
	}
	for (int i=1; i<=n; i++) {
		if (fb[i] < B or fa[i] < A) continue;
		int ja = Search_a(0,i-2,fa[i]-A);
		int jb = Search_b(0,i-2,fb[i]-B);
		int j = min(ja,jb);
		if (j == -1) continue;
		res = min(res, fd[i]-fd[j+1]);
	}
	if (res == LONG_LONG_MAX) cout << -1;
	else cout << res;
}*/
// #include<bits/stdc++.h>
// using namespace std;
// int n, a, b, ans = 1e9, x, y, dem1, dem2;
// pair <int, int> cay[300005];
// int main() {
// 	cin>>n>>a>>b;
// 	x = y = 1;
// 	for(int i=1;i<=n;i++) {
// 		cin>>cay[i].first>>cay[i].second;
// 	}
// 	sort(cay+1, cay+n+1);
// 	while(y<=n) {
// 		if(cay[y].second==1) dem1++;
// 		else dem2++;
// 		if(dem1>=a&&dem2>=b) ans = min(ans, cay[y].first - cay[x].first);
// 		while (dem1>=a && dem2>=b) {
// 			if(cay[x].second==1) dem1--;
// 			else dem2--;
// 			x++;
// 			if(dem1>=a && dem2>=b) ans = min(ans, cay[y].first - cay[x].first);
// 		}
// 		y++;
// 	}
// 	if(ans!=1e9) cout<<ans;
// 	else cout<<"-1";
// } 

// https://oj.vnoi.info/problem/minroad
#include <bits/stdc++.h>
using namespace std;

int n, a, b, num_t1, num_t2;
pair <int, int> trees[300005];

int main() {
    cin >> n >> a >> b;
    for(int i = 1; i <= n; i ++) {
        cin >> trees[i].first >> trees[i].second;
        if(trees[i].second == 1) num_t1 ++;
        else num_t2 ++;
    }
    if(num_t1 < a || num_t2 < b) {
        cout << "-1";
        return 0;
    }
    sort(trees + 1, trees + n + 1);
    deque <int> q1, q2;
    int ans = 1e9;
    for(int i = 1; i <= n; i ++) {
        if(q1.size() < a || q2.size() < b) {
            if(trees[i].second == 1) q1.push_back(i);
            else q2.push_back(i);
        }
        else {
            while(q1.size() > a) q1.pop_front();        
            while(q2.size() > b) q2.pop_front();
            ans = min(ans, max(trees[q2.back()].first, trees[q1.back()].first) - min(trees[q2.front()].first, trees[q1.front()].first));

            if(trees[i].second == 1) q1.push_back(i);
            else q2.push_back(i);
            
            while(q1.size() > a) q1.pop_front();        
            while(q2.size() > b) q2.pop_front();
            ans = min(ans, max(trees[q2.back()].first, trees[q1.back()].first) - min(trees[q2.front()].first, trees[q1.front()].first));
        }
    }
    cout << ans;
}