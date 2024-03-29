// https://oj.vnoi.info/problem/backtrack_a
#include <bits/stdc++.h>
using namespace std;

int n, k, mn = 1e9;
vector <int> ans;
vector <int> test;
int a[51][51], check[51];
int middle_vectices[51][51];

void find_middle_vertices() {
    for(int i = 1; i < n; i ++) {
        for(int j = i + 1; j <= n; j ++) {
            int mn1 = 1e9, index1 = 0, mn2 = 1e9, index2 = 1e9;
            for(int k = 1; k <= n; k ++) {
                if(k != i && k != j && a[i][k] + a[k][j] < mn1) {
                    mn1 = a[i][k] + a[k][j];
                    index1 = k;
                }
                if(k != i && k != j && a[j][k] + a[k][i] < mn2) {
                    mn2 = a[j][k] + a[k][i];
                    index2 = k;
                }
            }
            middle_vectices[i][j] = index1;
            middle_vectices[j][i] = index2;
        }
    }
}

void backtrack(int pos, int currentPos, int sum) {
    if(pos == k / 2 - 1) {
        sum += a[test.back()][middle_vectices[test.back()][1]] + a[middle_vectices[test.back()][1]][1];

        if(sum < mn) {
            mn = sum;
            ans = test;
        }
        return;
    }
    for(int i = 2; i <= n; i ++) {
        if(!check[i] && !check[middle_vectices[currentPos][i]]) {
            check[i] = 1;
            check[middle_vectices[currentPos][i]] = 1;
            sum += a[currentPos][middle_vectices[currentPos][i]] + a[middle_vectices[currentPos][i]][i];
            test.push_back(middle_vectices[currentPos][i]);
            test.push_back(i);
            backtrack(pos + 1, i, sum);
            sum -= a[currentPos][middle_vectices[currentPos][i]] + a[middle_vectices[currentPos][i]][i];
            test.pop_back();
            test.pop_back();
            check[i] = 0;
            check[middle_vectices[currentPos][i]] = 0;
        }
    }
}

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            cin >> a[i][j];
        }
    }
    find_middle_vertices();
    check[1] = 1;
    backtrack(0, 1, 0);
    cout << mn << endl;
    cout << "1 ";
    for(int i = 0; i < ans.size(); i ++) cout << ans[i] << " ";
    cout << middle_vectices[ans[ans.size() - 1]][1];
}