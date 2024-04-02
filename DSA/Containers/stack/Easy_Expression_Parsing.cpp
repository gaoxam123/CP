#include <bits/stdc++.h>
using namespace std;

string s;
stack <int> val;
stack <char> ops;

// main idea: if the next op is less or equal prioritized as the last op, then we process the last op first

int priority(char op) {
    return (op == '+' || op == '-') ? 1 : 2;
}

void process_ops(stack <int>& v, char op) {
    int r = v.top();
    v.pop();
    int l = v.top();
    v.pop();
    if(op == '+') v.push(l + r);
    if(op == '-') v.push(l - r);
    if(op == '*') v.push(l * r);
    if(op == '/') v.push(l / r);
}

bool isDigit(char c) {
    return '0' <= c && c <= '9';
}

int evaluate(string s) {
    for(int i = 0; i < s.size(); i ++) {
        if(isDigit(s[i])) {
            int number = 0;
            while(i < s.size() && isDigit(s[i])) {
                number = number * 10 + s[i] - '0';
                i ++;
            }
            i --;
            val.push(number);
        }
        else {
            char currentOp = s[i];
            while(!ops.empty() && priority(ops.top()) >= priority(s[i])) {
                process_ops(val, ops.top());
                ops.pop();
            }
            ops.push(s[i]);
        }
    }
    while(!ops.empty()) {
        process_ops(val, ops.top());
        ops.pop();
    }
    return val.top();
}

int main() {
    cin >> s;
    cout << evaluate(s);
}