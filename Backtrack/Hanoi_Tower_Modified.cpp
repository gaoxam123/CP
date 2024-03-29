// https://oj.vnoi.info/problem/backtrack_b
#include <bits/stdc++.h>
using namespace std;

int n, a[23], cnt;
string s;
string str;
vector <char> ans;

void backtrack(int x, int tower) {
	if(x == 0) {
        if(a[x] == tower) return;
        ans.push_back(str[a[x]]);
        ans.push_back(str[tower]);
		a[x] = tower;
        cnt ++;
		return;
	}
    if(a[x] == tower) {
        backtrack(x - 1, tower);
    }
    else {
        backtrack(x - 1, 3 - tower - a[x]);
        ans.push_back(str[a[x]]);
        ans.push_back(str[tower]);
        a[x] = tower;
        cnt ++;
        backtrack(x - 1, tower);
    }
}

int main() {
    cin >> n;
    cin >> s;
    str = "ABC";
    for(int i = 0; i < s.size(); i ++) {
        if(s[i] == 'A') a[i] = 0;
        else if(s[i] == 'B') a[i] = 1;
        else a[i] = 2;
    }
    backtrack(n - 1, 2);
    cout << ans.size() / 2 << endl;
    for(int i = 0; i < ans.size(); i ++) {
        cout << ans[i];
        if(i % 2 == 1) cout << endl;
    }
}