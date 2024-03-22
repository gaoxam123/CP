#include<bits/stdc++.h>
using namespace std;
int n, a[100005], L[100005], R[100005], ans, t;
stack <int> st;
int main() {
	cin >> t;
	while(t --) {
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i ++) cin >> a[i];
		for (int i = 1; i <= n; i ++) {
			while (! st.empty() && a[i] <= a[st.top()]) st.pop();
			if(st.empty()) L[i] = 1;
			else L[i] = st.top() + 1;
			st.push(i);
		}
		while (!st.empty()) st.pop();
		for (int i = n; i >= 1; i --) {
  			while (! st.empty() && a[i] <= a[st.top()]) st.pop();
  			if(st.empty()) R[i] = n;
  			else R[i] = st.top() - 1;
  			st.push(i);
 		}
 		while (!st.empty()) st.pop();
 		for (int i = 1; i <= n; i ++) 
 			if ((R[ans] - L[ans] + 1) * a[ans] < (R[i] - L[i] + 1) * a[i]) ans = i;
 		cout << (R[ans] - L[ans] + 1) * a[ans] << " " << L[ans] << " " << R[ans] << endl;
 	}
}
