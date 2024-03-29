// https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=515
#include <bits/stdc++.h>
using namespace std;

map <vector <int>, bool> check;
int target_sum, n, a[25], cnt;
vector <int> ans;

void backtrack(int pos, int sum) {
    if(pos == n) {
        // check if target sum is reached and if the sequence of number has already appeared
        if(sum == target_sum && check[ans] == false) {
            cnt ++;
            check[ans] = true;
            for(int i = 0; i < ans.size(); i ++) {
                cout << ans[i];
                if(i < ans.size() - 1) cout << "+";
            }
            cout << endl;
        }
        return;
    }
    // add an element to the vector
    ans.push_back(a[pos]);
    backtrack(pos + 1, sum + a[pos]);
    // remove the element
    ans.pop_back();
    backtrack(pos + 1, sum);
}

int main() {
    while(cin >> target_sum) {
        if(target_sum == 0) return 0;
        cin >> n;
        for(int i = 0; i < n; i ++) {
            cin >> a[i];
        }
        cnt = 0;
        cout << "Sums of " << target_sum << ":" << endl;
        backtrack(0, 0);
        if(cnt == 0) cout << "NONE" << endl;
    }
}