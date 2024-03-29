// https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=565
#include <bits/stdc++.h>
using namespace std;

int n, a[25], mx = -1e9, max_length;
vector <int> ans, test;

void backtrack(int pos, int sum) {
    if(pos == n) {
        if(sum > mx && sum <= max_length) {
            mx = sum;
            ans = test;
        }
        return;
    }
    // add an element
    test.push_back(a[pos]);
    backtrack(pos + 1, sum + a[pos]);
    // remove the element
    test.pop_back();
    backtrack(pos + 1, sum);
}

int main() {
    while(cin >> max_length) {
        if(max_length == 0) return 0;
        cin >> n;
        for(int i = 0; i < n; i ++) cin >> a[i];
        mx = -1e9;
        backtrack(0, 0);
        int sum = 0;
        for(int i = 0; i < ans.size(); i ++) {
            sum += ans[i];
            cout << ans[i] << " ";
        }
        cout << "sum:" << sum << endl;
    }
}