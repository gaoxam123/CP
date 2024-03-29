// https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=2026
#include <bits/stdc++.h>
using namespace std;

// array test contains the rows of column i
int test[10], a[10], ans, test_case_count;

// check if 2 queens are on the same row or the same diagonal
bool checkValid(int row, int column) {
    for(int i = 1; i < column; i ++) {
        if(row == test[i] || abs(row - test[i]) == abs(column - i)) return false;
    }
    return true;
}

// add in row i if valid
// compute the required move of each permutation and take the min value
void backtrack(int column) {
    for(int i = 1; i <= 8; i ++) {
        if(checkValid(i, column)) {
            test[column] = i;
            if(column == 8) {
                int cnt = 0;
                for(int j = 1; j <= 8; j ++) {
                    if(test[j] != a[j]) cnt ++;
                }
                ans = min(ans, cnt);
            }
            backtrack(column + 1);
        }
    }
}

int main() {
    while(true) {
        test_case_count ++;
        for(int i = 1; i <= 8; i ++) {
            cin >> a[i];
        }
        ans = 1e9;
        backtrack(1);
        cout << "Case " << test_case_count << ": " << ans << endl;
    }
}