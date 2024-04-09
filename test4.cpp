#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m, a[15], cnt, t;
stack <int> ops, value;
int sign[15];

int priority(int op) {
    return (op == 1 || op == 2) ? 1 : 2;
}

void process(stack <int>& val, int op) {
    int r = val.top();
    val.pop();
    int l = val.top();
    val.pop();
    if(op == 3) val.push(l * r);
    if(op == 2) val.push(l - r);
    if(op == 1) val.push(l + r);
}

void backtrack(int pos) {
    if(pos == n) {
        // compute the value of the expression
        value.push(a[1]);
        for(int i = 2; i <= n; i ++) {
            while(!ops.empty() && priority(ops.top()) >= priority(sign[i])) {
                process(value, ops.top());
                ops.pop();
            }
            ops.push(sign[i]);
            value.push(a[i]);
        }
        while(!ops.empty()) {
            process(value, ops.top());
            ops.pop();
        }
        if(value.top() % m == 0) {
            cnt ++;
        }
        while(!value.empty()) value.pop();
        return;
    }
    sign[pos + 1] = 1; // +
    backtrack(pos + 1);
    sign[pos + 1] = 2; // -
    backtrack(pos + 1);
    sign[pos + 1] = 3; // *
    backtrack(pos + 1);
}

signed main() {
    cin >> t;
    while(t --) {
        cin >> n >> m;
        for(int i = 1; i <= n; i ++) {
            cin >> a[i];
        }
        cnt = 0;
        memset(sign, 0, sizeof(sign));
        backtrack(1);
        cout << cnt << endl;
    }
}

