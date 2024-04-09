#include <bits/stdc++.h>
using namespace std;

const int N = 9;

void print(int a[N][N]) {
    for(int i = 0; i < 9; i ++) {
        for(int j = 0; j < 9; j ++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int a[N][N], int row, int col, int curr_num) {
    for(int i = 0; i < 9; i ++) {
        if(a[row][i] == curr_num) return false;
    } 
    for(int i = 0; i < 9; i ++) {
        if(a[i][col] == curr_num) return false;
    }
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for(int i = 0; i < 3; i ++) {
        for(int j = 0; j < 3; j ++) {
            if(a[startRow + i][startCol + j] == curr_num) return false;
        }
    }
    return true;
}

bool solve(int a[N][N], int row, int col) {
    if(row == N - 1 && col == N) return true;
    if(col == N) {
        col = 0;
        row ++;
    }
    if(a[row][col] > 0) solve(a, row, col + 1);
    for(int i = 1; i <= 9; i ++) {
        if(isSafe(a, row, col, i)) {
            a[row][col] = i;
            if(solve(a, row, col + 1)) return true;
        }
        a[row][col] = 0;
    }
    return false;
}

int a[N][N];

int main() {
    for(int i = 0; i < 9; i ++) {
        for(int j = 0; j < 9; j ++) {
            cin >> a[i][j];
        }
    }
    if(solve(a, 0, 0)) print(a);
    else cout << "-1";
}