#include <bits/stdc++.h>
using namespace std;

int t, n, a[100005], cnt;

int main() {
    cin >> t;
    while(t --) {
        cin >> n;
        int index;
        cnt = 0;
        if(n % 2 == 0) index = n / 2;
        else index = n / 2 + 1;
        for(int i = 1; i <= n; i ++) {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        for(int i = 1; i <= n; i ++) {
            if(i >= index && a[i] == a[index]) cnt ++;
        }
        cout << cnt << endl;
    }
}