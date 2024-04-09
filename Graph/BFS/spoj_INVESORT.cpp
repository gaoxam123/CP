// https://www.spoj.com/problems/INVESORT/
#include <bits/stdc++.h>
using namespace std;

void rev(int l, int r, string &s) {
    while(l < r) {
        swap(s[l ++], s[r --]);
    }
}

int solve(string start, string end) {
    if(start == end) return 0;
    int steps = 0;
    queue <string> q;
    unordered_set <string> s;
    q.push(start);
    s.insert(start);
    while(!q.empty()) {
        int n = q.size();
        while(n --) {
            string next = q.front();
            q.pop();
            for(int i = 0; i < 10; i ++) {
                for(int j = i + 1; j < 10; j ++) {
                    string t = next;
                    rev(i, j, t);
                    if(t == end) return steps + 1;
                    if(s.find(t) == s.end()) {
                        s.insert(t);
                        q.push(t);
                    }
                }
            }
        }
        steps ++;
    }
    return -1;
}

string s, e;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                    
    cout.tie(NULL);
    while(true) {
        cin >> s >> e;
        if(s == "*" || e == "*") return 0;
        cout << solve(s, e) << endl;
    }
}