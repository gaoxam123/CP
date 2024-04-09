// https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=691
#include <bits/stdc++.h>
using namespace std;

// array test contains the rows of column i
int test[10], temp1, temp2, t, cnt;

// check if 2 queens are on the same row or the same diagonal
bool checkValid(int row, int column) {
    for(int i = 1; i < column; i ++) {
        if(row == test[i] || abs(row - test[i]) == abs(column - i)) return false;
    }
    return true;
}

// add in row i if valid, then check if the permutation contains the target coordinate of 1 queen
void backtrack(int column) {
    for(int i = 1; i <= 8; i ++) {
        if(checkValid(i, column)) {
            test[column] = i;
            if(column == 8) {
                if(test[temp2] == temp1) {
                    cout << cnt ++ << "\t";
                    for(int j = 1; j <= 8; j ++) {
                        cout << test[j] << " ";
                    }
                    cout << endl;
                }
                return;
            }
            backtrack(column + 1);
        }
    }
}

int main() {
    cin>>t;
	cout << "SOLN\tCOLUMN" << endl << "#\t1 2 3 4 5 6 7 8" << endl << endl;
	while(t --){
		cin >> temp1 >> temp2;
		cnt = 1;
		backtrack(1);
		cout << endl;
	}
}