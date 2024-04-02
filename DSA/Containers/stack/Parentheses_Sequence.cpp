#include <bits/stdc++.h>
using namespace std;

string s;
stack <int> st;
vector <pair <int, int> > matches;

// idea: put ( in the stack, if ) shows up, pop the top

int main() {
    cin >> s;
    for(int i = 0; i < s.size(); i ++) {
        if(s[i] == '(') {
            st.push(i);
        }
        else {
            if(st.empty()) {
                cout << "-1";
                return 0;
            }
            matches.push_back(make_pair(st.top(), i));
            st.pop();
        }
        if(!st.empty()) {
            cout << "-1";
            return 0;
        }
    }
    for(int i = 0; i < matches.size(); i ++) {
        cout << matches[i].first << " " << matches[i].second << endl;
    }
}