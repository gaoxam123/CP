#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data[3];
    Node *first, *second, *third, *fourth;
    Node *getChild(int index);
};

Node *Node::getChild(int index) {
    if(index == 0) return this->first;
    if(index == 1) return this->second;
    if(index == 2) return this->third;
    else return this->fourth;
}

Node *newNode(int data[]) {
    Node *tmp = new Node;
    for(int i = 0; i < 3; i ++) {
        tmp->data[i] = data[i];
    }
    tmp->first = tmp->second = tmp->third = tmp->fourth = NULL;
    return tmp;
}

void toList(Node *root) {
    vector<int> v;
    stack<Node*> st;
    st.push(root);

    while (!st.empty()) {
        Node* current = st.top();
        st.pop();

        if (current != nullptr) {
            v.push_back(current->data[0]);
            v.push_back(current->data[1]);
            v.push_back(current->data[2]);

            // Push child nodes in reverse order to maintain the correct order
            st.push(current->third);
            st.push(current->fourth);
            st.push(current->second);
            st.push(current->first);
        }
    }

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
}

int main() {
    int a[]{4, 8, 12};
    Node *root = newNode(a);
    int b[]{1, 2, 3};
    root->first = newNode(b);
    int c[]{5, 6, 7};
    root->second = newNode(c);
    int d[]{9, 10, 11};
    root->third = newNode(d);
    int e[]{13, 14, 15};
    root->fourth = newNode(e);

    toList(root);

    return 0;
}