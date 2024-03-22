#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
    void setVal(int val) {
        this->data = val;
    }
};

class BST {
private:
    Node *root;
    Node *Del(Node *node, int val);

public:
    BST();
    
    void insert(int val);
    Node *search(int val);
    void Delete(int val);
    Node *findMin(Node *node);
    void updateNode(int val1, int val2);
    void display();
};

BST::BST() {
    root = nullptr;
}

void BST::insert(int val) {
    Node *newNode = new Node(val);

    if(root == nullptr) {
        root = newNode;
        return;
    }

    Node *current = root;
    while(true) {
        if(val < current->data) {
            if(current->left == nullptr) {
                current->left = newNode;
                break;
            }
            else current = current->left;
        }
        else {
            if(current->right == nullptr) {
                current->right = newNode;
                break;
            }
            else current = current->right;
        }
    }
}

Node *BST::search(int val) {
    Node *current = root;
    while(current != nullptr) {
        if(val == current->data) return current;     
        if(val < current->data) current = current->left;
        else current = current->right;  
    }
}

void BST::Delete(int val) {
    root = Del(root, val);
}

Node *BST::findMin(Node *node) {
    while(node->left != nullptr) node = node->left;
    return node;
}

Node *BST::Del(Node *node, int val) {
    if(node == nullptr) return nullptr;
    if(val < node->data) node->left = Del(node->left, val);
    else if(val > node->data) node->right = Del(node->right, val);
    else {
        if(node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
        }
        else if(node->left == nullptr) {
            Node *tmp = node;
            node = node->right;
            delete tmp;           
        }
        else if(node->right == nullptr) {
            Node *tmp = node;
            node = node->left;
            delete tmp;
        }
        else {
            Node *tmp = findMin(node->right);
            node->data = tmp->data;
            node->right = Del(node->right, tmp->data);
        }
    }
    return node;
}

void BST::updateNode(int val1, int val2) {
    Node *tmp = this->search(val1);
    (*tmp).setVal(val2);      
}

queue <Node*> q;

void BST::display() {
    q.push(root);
    cout << root->data << " ";
    while(! q.empty()) {
        Node *tmp = q.front();
        q.pop();
        if(tmp->left != nullptr) {
            cout << (*tmp->left).data << " ";
            q.push(tmp->left);
        }
        if(tmp->right != nullptr) {
            cout << (*tmp->right).data << " ";
            q.push(tmp->right);
        }
    }
}

int main() {
    BST bst;
    bst.insert(8);
    bst.insert(3);
    bst.insert(69);
    bst.insert(100);
    bst.Delete(100);
    
    bst.display();
}