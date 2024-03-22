#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data[3];
    int idx;
    Node *first, *second, *third, *fourth;
    void insert(int value);
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
    tmp->idx = 0;
    return tmp;
}

// void Node::insert(int value) {
//     for(int i = 0; i < 3; i ++) {
//         if(this->data[i] > value) {
//             if(this->getChild(i) != NULL) {
//                 this->getChild(i)->insert(value);
//             }
//             else {

//                 this->getChild(i) = newNode()
//             }
//         }
//     }
// }

vector <int> v;

void toList(Node *node) {
    if(node == NULL) return;
    toList(node->first);
    v.push_back(node->data[0]);
    toList(node->second);
    v.push_back(node->data[1]);
    toList(node->third);
    v.push_back(node->data[2]);
    toList(node->fourth);
}

void toListVer2(Node *node) {
    stack <Node*> st;
    st.push(node);
    Node* current = st.top();
    while(!st.empty()) {
        if(current->idx % 2 == 1) {
            v.push_back(current->data[current->idx / 2]);
            current->idx++;
            while(current != NULL && (current->idx > 6)) {
                st.pop();
                current = st.top();
            }
        }
        else {
            if(current->getChild(current->idx / 2) == NULL) {
                current->idx ++;
                continue;
            }
            current = current->getChild(current->idx / 2);
            st.top()->idx++;
            st.push(current);
        }
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
    toListVer2(root);
    for(int i = 0; i < v.size(); i ++) {
        cout << v[i] << " ";
    }
}