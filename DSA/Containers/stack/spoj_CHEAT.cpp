// https://oj.vnoi.info/problem/cheat
#include <bits/stdc++.h>
using namespace std;

int n, a[100005], x;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    stack <int> st;
    for(int i = 1; i <= n; i ++) {
        if(a[i] > a[i - 1]) {
            for(x = x + 1; x < a[i]; x ++) st.push(x);
        }
        else {
            if(!st.empty() && st.top() == a[i]) st.pop();
            else  {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
}